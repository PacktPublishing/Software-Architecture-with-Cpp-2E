# Software Architecture with C++, Second Edition

Software Architecture with C++: Designing Robust C++ Systems with Modern Architectural Practices, Second Edition, published by Packt

## Chapter 15: Interservice communication

### Prerequisites

Install the following software:

- CMake 3.28
- Conan 2
- GCC 15, Clang 20, MSVC 19.44 (VS 2022) or 19.50 (VS 2026)

The C++ compiler in your IDE and the Conan profile must be compatible to compile examples from the IDE.

Assuming you're on Linux or using WSL. The examples are developed on Linux, but their compilation and
functionality are also tested on macOS and Windows.

Configure a local Conan profile and remotes by running:

```bash
rm -rf ./build/
conan profile detect --name ./build/conan_profile
```

Make sure that the profile section `[settings]` contains:

```text
arch=x86_64
compiler=gcc
compiler.libcxx=libstdc++11
compiler.version=15
os=Linux
```

### Building

To build the project, configure the Conan profile as described above, cd to its directory, and then run:

```bash
cd build
conan install .. --build=missing -s build_type=Release -pr:a=./conan_profile -of .
cmake .. -DCMAKE_BUILD_TYPE=Release # build type must match Conan's
cmake --build .
```

If GCC 15 is not your default compiler, you can tell CMake to use it with the `CMAKE_CXX_COMPILER` flag:

```bash
cd build
conan install .. --build=missing -s build_type=Release -pr:a=./conan_profile -of .
cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_COMPILER=`which g++-15` # build type must match Conan's
cmake --build .
```

To pass the settings directly without a Conan profile, use the command line option `--settings:all` or `-s:a`, and the keys `arch`, `build_type`, `compiler`, `compiler.cppstd`, `compiler.libcxx`, `compiler.version`, `os`:

```bash
rm -rf ./build/ && mkdir build && cd build
conan install .. --build=missing -s:a build_type=Release -s:a compiler=gcc -of .
cmake .. -DCMAKE_BUILD_TYPE=Release # build type must match Conan's
cmake --build .
```

To apply Conan dependency as a CMake Dependency Provider, clone this Git repository and then run the next command:

```bash
rm -rf ./build/cmake-conan
git clone https://github.com/conan-io/cmake-conan.git build/cmake-conan
```

```bash
cmake -S . -B build -DCMAKE_PROJECT_TOP_LEVEL_INCLUDES=./build/cmake-conan/conan_provider.cmake -DCMAKE_BUILD_TYPE=Release
cmake --build build
```

### Troubleshooting

The cppgraphqlgen library may be incompatible with Clang, so try either GCC or MSVC (chosen simultaneously in Conan and IDE).
Conan can determine current C and C++ compilers from the CC and CXX environment variables.

The Boost library depends on the Python interpreter installed on the system.
So, this library may require installing additional Python modules such as numpy.
The compiled library can be downloaded from the official [website](https://www.boost.org/releases/latest/).

The Conan profile for MSVC 19.50 (Visual Studio 2026) may look like this one:

```
[settings]
arch=x86_64
os=Windows
compiler=msvc
compiler.version=195
compiler.runtime=dynamic
compiler.cppstd=20
compiler.cstd=17
[conf]
tools.cmake.cmaketoolchain:generator=Ninja
tools.build:compiler_executables={"cpp":"C:/Program Files/Microsoft Visual Studio/18/Community/VC/Tools/MSVC/14.50.35717/bin/Hostx64/x64/cl.exe","rc":"C:/Program Files (x86)/Windows Kits/10/bin/10.0.26100.0/x64/rc.exe"}
tools.microsoft.msbuild:vs_version=18
```

However, if Conan packages are not built, it may make sense to try previous versions of MSVC Build Tools.
The same C++ compiler must also be chosen in the IDE settings.
Thus, The Conan profile for MSVC 19.44 (Visual Studio 2026) may look like this one:

```
[settings]
arch=x86_64
build_type=Release
compiler=msvc
compiler.cppstd=20
compiler.runtime=dynamic
compiler.version=194
os=Windows
[conf]
tools.cmake.cmaketoolchain:generator=Ninja
tools.build:compiler_executables={"cpp":"C:/Program Files/Microsoft Visual Studio/18/Community/VC/Tools/MSVC/14.44.35207/bin/Hostx64/x64/cl.exe","rc":"C:/Program Files (x86)/Windows Kits/10/bin/10.0.26100.0/x64/rc.exe"}
tools.microsoft.msbuild:vs_version=18
```
