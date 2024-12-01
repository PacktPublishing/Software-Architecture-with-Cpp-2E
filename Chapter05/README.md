# Software Architecture with C++, Second Edition

Software Architecture with C++, Second Edition, Published by Packt

## Chapter 5: Leveraging C++ Language Features

### Prerequisites

Install the following software:

- CMake 3.28
- Conan 2.9.3
- GCC 14
- Ninja 1.11

[CMake 3.28: Generator Support](https://cmake.org/cmake/help/v3.28/manual/cmake-cxxmodules.7.html#limitations)

The list of generators which support scanning sources for C++ modules include:
- Ninja
- Ninja Multi-Config
- Visual Studio 17 2022

Assuming you're on Linux or using WSL, configure a Conan profile and remotes by running:

```bash
rm -rf ./build/
conan profile detect --name ./build/conan_profile
```

Make sure that the profile section `[settings]` contains:

```text
arch=x86_64
compiler=gcc
compiler.libcxx=libstdc++11
compiler.version=14
os=Linux
```

### Building

To build the project, configure the Conan profile as described above, cd to its directory, and then run:

```bash
cd build
conan install .. --build=missing -s build_type=Release -pr:a=./conan_profile -of .
cmake .. -G Ninja -DCMAKE_BUILD_TYPE=Release # build type must match Conan's
cmake --build .
```

If GCC 14 is not your default compiler, you can tell CMake to use it with the `CMAKE_CXX_COMPILER` flag:

```bash
cd build
conan install .. --build=missing -s build_type=Release -pr:a=./conan_profile -of .
cmake .. -G Ninja -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_COMPILER=`which g++-14` # build type must match Conan's
cmake --build .
```
