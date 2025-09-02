# Software Architecture with C++, Second Edition

Software Architecture with C++: Designing Robust C++ Systems with Modern Architectural Practices, Second Edition, published by Packt

## Chapter 15: Architecture of Distributed Systems

### Prerequisites

Install the following software:

- CMake 3.28
- Conan 2
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

**Important**: MinIO's dependency requires Python 3

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

### MinIO Console

The [MinIO Console](https://docs.min.io/community/minio-object-store/administration/minio-console.html) is
a rich graphical user interface that supports browsing buckets and objects on your deployment.
You can explore the console by opening https://play.min.io:9443 in a browser. Log in with the following credentials:

- Username: Q3AM3UQ867SPQQA43P2F
- Password: zuf+tfteSlswRu7BJ86wekitnifILbZam1KYY3TG
