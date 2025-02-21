# Software Architecture with C++, Second Edition

Software Architecture with C++, Second Edition, Published by Packt

## Chapter 10: Writing Testable Code

### Prerequisites

Install the following software:

- CMake 3.28
- Conan 2.12
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
compiler.cppstd=gnu20
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

To pass the settings directly without a Conan profile, use the command line option `--settings:all` or `-s:a`, and the keys `arch`, `build_type`, `compiler`, `compiler.cppstd`, `compiler.libcxx`, `compiler.version`, `os`:

```bash
rm -rf ./build/ && mkdir build && cd build
conan install .. --build=missing -s:a build_type=Release -s:a compiler=gcc -s:a compiler.cppstd=gnu20 -of .
cmake .. -G Ninja -DCMAKE_BUILD_TYPE=Release # build type must match Conan's
cmake --build .
```

To apply Conan dependency as a CMake Dependency Provider, clone this Git repository and then run the next command:

```bash
rm -rf ./build/cmake-conan
git clone https://github.com/conan-io/cmake-conan.git build/cmake-conan
```

```bash
cmake -S . -B build -DCMAKE_PROJECT_TOP_LEVEL_INCLUDES=./build/cmake-conan/conan_provider.cmake -G Ninja -DCMAKE_BUILD_TYPE=Release
cmake --build build
```

### Testing

To run tests from each of the projects, cd into their respective build directory, and then simply run `ctest`.

### Troubleshooting

If you see this error, edit `~/.conan2/profiles/default` and set `compiler.cppstd=gnu20` (or higher):

```
boost-ext-ut/*: Invalid: Current cppstd (gnu17) is lower than the required C++ standard (20).
```

### Troubleshooting

Windows Firewall can block connections to the IP address 0.0.0.0 therefore set 127.0.0.1 in customer/src/customer/main.cpp
as a workaround or allow connections to that address
