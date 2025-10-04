# Software Architecture with C++, Second Edition

Software Architecture with C++: Designing Robust C++ Systems with Modern Architectural Practices, Second Edition, published by Packt

## Chapter 9: The Future of C++ Code Reuse: Using Modules

### Prerequisites

Install the following software:

- CMake 4.0
- Conan 2
- GCC 15

The C++ compiler in your IDE and the Conan profile must be compatible if the examples are compiled from the IDE.

Assuming you're on Linux or using WSL, configure a local Conan profile and remotes by running:

```bash
rm -rf ./build/
conan profile detect --name ./build/conan_profile
```

Make sure that the profile section `[settings]` contains:

```text
arch=x86_64
compiler=gcc
compiler.cppstd=gnu23
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

If GCC 14 is not your default compiler, you can tell CMake to use it with the `CMAKE_CXX_COMPILER` flag:

```bash
conan install . --build=missing -s build_type=Release -pr:a=./build/conan_profile
cmake --preset conan-release -DCMAKE_CXX_COMPILER=`which g++-14`
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
cmake --build build
```

### Installing

In the build directory, run `cmake --install .` to install the software into `${CMAKE_PREFIX_PATH}`. If no prefix is
given, it will install system-wide. To change this, add `-DCMAKE_INSTALL_PREFIX=/path/to/install/to` to your cmake
invocation.

### Building the Conan package

In the directory containing `conanfile.py`, run:

```bash
rm -rf ./build
conan build .
conan export-pkg .
```

The command `conan export-pkg .` also runs this test:

```bash
conan test test_package stores/0.0.4
```

Or run this command that includes the other stages to create the package:

```bash
conan create .
```

### Troubleshooting

Your environment may need some adjustment for GCC and Clang:

- Clang: pass the flags -DCMAKE_CXX_FLAGS=-stdlib=libc++
