# Software Architecture with C++, Second Edition

Software Architecture with C++, Second Edition, Published by Packt

## Chapter 10: Writing Testable Code

### Prerequisites

Install the following software:

- CMake 3.28
- Conan 2.11.0
- GCC 14

Assuming you're on Linux or using WSL, configure a local Conan profile and remotes by running:

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
cmake .. -DCMAKE_BUILD_TYPE=Release # build type must match Conan's
cmake --build .
```

If GCC 14 is not your default compiler, you can tell CMake to use it with the `CMAKE_CXX_COMPILER` flag:

```bash
cd build
conan install .. --build=missing -s build_type=Release -pr:a=./conan_profile -of .
cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_COMPILER=`which g++-14` # build type must match Conan's
cmake --build .
```

To pass the settings directly without a Conan profile, use the command line option `--settings` or `-s`, and the keys `os`, `arch`, `compiler`, `build_type`, `cppstd`:

```bash
rm -rf ./build/ && mkdir build && cd build
conan install .. --build=missing -s build_type=Release -s compiler="gcc" -of .
cmake .. -DCMAKE_BUILD_TYPE=Release # build type must match Conan's
cmake --build .
```

### Testing

To run tests from each of the projects, cd into their respective build directory, and then simply run `ctest`.
