# Software Architecture with C++, Second Edition

Software Architecture with C++, Second Edition, Published by Packt

## Chapter 17: Service Oriented Architecture

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
compiler.libcxx=libstdc++11
compiler.version=14
os=Linux
```

### Building

**Important**: AWS SDK for C++ requires development libraries out of Conan packages

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

### Running the example application

You need valid AWS credentials for the program to run successfully.

Get your credentials by following this document:
https://docs.aws.amazon.com/sdk-for-javascript/v2/developer-guide/getting-your-credentials.html

If you are creating a new user just for testing, you can attach the
`AdministratorAccess` policy to the created user. For production use, apply
fine-grained permissions.

Set the environment variables to the values you got from IAM using:

```
export AWS_ACCESS_KEY_ID="anaccesskey"
export AWS_SECRET_ACCESS_KEY="asecretkey"
```

If you are using Direnv, you can also put these variables to your `.env` file in
the current directory. Fill in your secret values in the `env.example` file and
rename it to `.env`.

The application creates an S3 bucket in AWS.

**Important**: Make sure to delete it after
testing or you may be billed by the AWS. You can check the S3 bucket at
https://s3.console.aws.amazon.com/s3/home?region=eu-central-1# (switch the
region accordingly with the one in the code).
