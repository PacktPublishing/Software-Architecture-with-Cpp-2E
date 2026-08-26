# Software Architecture with C++, Second Edition

Software Architecture with C++: Designing Robust C++ Systems with Modern Architectural Practices, Second Edition, published by Packt

## Chapter 12: Security in Code and Deployment

### Prerequisites

Install the following software:

- CMake 3.28
- Conan 2
- GCC 15, Clang 20, MSVC 19.50

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
compiler.cppstd=gnu17
compiler.cstd=gnu17
compiler.libcxx=libstdc++11
compiler.version=15
os=Linux
```

### Building

To build the project, configure the Conan profile as described above, cd to its directory, and then run:

```bash
conan install . --build=missing -s build_type=Release -pr:a=./build/conan_profile
cmake --preset conan-release
cmake --build --preset conan-release
```

If GCC 15 is not your default compiler, you can tell CMake to use it with the `CMAKE_CXX_COMPILER` flag:

```bash
conan install . --build=missing -s build_type=Release -pr:a=./build/conan_profile
cmake --preset conan-release -DCMAKE_CXX_COMPILER=`which g++-15`
cmake --build --preset conan-release
```

To pass the settings directly without a Conan profile, use the command line option `--settings:all` or `-s:a`, and the keys `arch`, `build_type`, `compiler`, `compiler.cppstd`, `compiler.libcxx`, `compiler.version`, `os`:

```bash
rm -rf ./build/
conan install . --build=missing -s:a build_type=Release -s:a compiler=gcc
cmake --preset conan-release
cmake --build --preset conan-release
```

To apply Conan dependency as a CMake Dependency Provider, clone this Git repository and then run the next command:

```bash
rm -rf ./build/cmake-conan
git clone https://github.com/conan-io/cmake-conan.git build/cmake-conan
```

```bash
cmake -G Ninja -S . -B build -DCMAKE_PROJECT_TOP_LEVEL_INCLUDES=./build/cmake-conan/conan_provider.cmake -DCMAKE_BUILD_TYPE=Release
cmake --preset conan-release
cmake --build --preset conan-release
```

### Troubleshooting

Windows Firewall can block connections to the IP address 0.0.0.0 therefore set 127.0.0.1 in customer/src/customer/main.cpp
as a workaround or allow connections to that address on the host.

The value of the PATH environment variable from the preset can be ignored when building from the CLion IDE and the `drogon-ctl` utility is not detected.
In this case, you need to reload the CMake project after configuring the project, load new presets and enable these profiles in the IDE.
Then, **explicitly** select the build profile with a name such as `conan-release - conan-release` and `conan-debug - conan-debug`.
It passes the preset option to CMake and injects the PATH value.

```bash
conan install -r conancenter --update . --build=missing
cmake --preset conan-release -DCMAKE_VERBOSE_MAKEFILE=ON
cmake --build --preset conan-release
```
