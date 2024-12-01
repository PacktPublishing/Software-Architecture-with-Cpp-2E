# Software-Architecture-with-C-2E

Software Architecture with C++, Second Edition, Published by Packt

## Chapter 2: Architectural Styles

### Prerequisites

Install the following software:

- CMake 3.16
- Conan 2.9.2
- GCC 13

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
compiler.version=13
os=Linux
```

If GCC 13 is not your default compiler, you can define a Python dict-like with the compilers path in the section `[conf]`:

```text
tools.build:compiler_executables={"c": "g++-13", "cpp": "gcc-13"}
```

Conan profiles are rendered as Jinja2 templates, which must result in standard text profiles.

### Building

To build the project, configure the Conan profile as described above, cd to its directory, and then run:

```bash
cd build
conan install .. --build=missing -s build_type=Release -pr:a=./conan_profile -of .
cmake .. -DCMAKE_BUILD_TYPE=Release # build type must match Conan's
cmake --build .
```

If GCC 13 is not your default compiler, you can tell CMake to use it with the `CMAKE_CXX_COMPILER` flag:

```bash
cd build
conan install .. --build=missing -s build_type=Release -pr:a=./conan_profile -of .
cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_COMPILER=`which g++-13` # build type must match Conan's
cmake --build .
```
