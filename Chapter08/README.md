# Software Architecture with C++, Second Edition

Software Architecture with C++, Second Edition, Published by Packt

## Chapter 8: Package Management

### Prerequisites

Install the following software:

- CMake 3.28
- Conan 2.13
- GCC 14

For optional packaging with CPack:

- dpkg build tools: [dh_make](https://manpages.ubuntu.com/manpages/trusty/man8/dh_make.8.html) and [dpkg-buildpackage](https://manpages.ubuntu.com/manpages/trusty/man1/dpkg-buildpackage.1.html) to assemble DEB packages
- rpm build tools: [rpmbuild](https://manpages.ubuntu.com/manpages/trusty/man8/rpmbuild.8.html) to assemble RPM packages

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
cmake -S . -B build -DCMAKE_PROJECT_TOP_LEVEL_INCLUDES=./build/cmake-conan/conan_provider.cmake -DCMAKE_BUILD_TYPE=Release
cmake --build build
```

### Testing

To run tests from each of the projects, cd into their respective build directory, and then simply run `ctest`.

### Installing

In the build directory, run `cmake --install .` to install the software into `${CMAKE_PREFIX_PATH}`. If no prefix is
given, it will install system-wide. To change this, add `-DCMAKE_INSTALL_PREFIX=/path/to/install/to` to your cmake
invocation.

### Packaging

In the build directory, run `cpack`. Simple as that. Assuming you're running on a system supporting DEB packages,
you'll get a .tar.gz file, a .zip file, a .deb package and an AppImage executable.

### Troubleshooting

Windows Firewall can block connections to the IP address 0.0.0.0 therefore set 127.0.0.1 in customer/src/customer/main.cpp
as a workaround or allow connections to that address

### Building the Conan package

In the directory containing `conanfile.py`, run:

```bash
rm -rf ./build
conan install . --build=missing
conan build .
conan export-pkg .
```

The command `conan export-pkg .` also runs this test:

```bash
conan test test_package customer/0.0.1
```

Or run this command that includes the other stages to create the package:

```bash
conan create . --build=missing
```

### Uploading the Conan package

[Run Artifactory CE](https://docs.conan.io/2/tutorial/conan_repositories/setting_up_conan_remotes/artifactory/artifactory_ce_cpp.html)
using Docker Compose and wait because the server takes a while to start:

```bash
cd docker
docker compose up -d
```

Open the URL `http://localhost:8081` in a browser. The default user and password are `admin:password`.
Navigate to `Administration -> Repositories`, then click on the `Create a Repository` button, select `Local` and the Package Type `Conan`.
For example, type `conan-local` in the `Repository key` and click on `Create Local Repository`.

Connect the Conan remote repository:

```bash
conan remote add artifactory http://localhost:8081/artifactory/api/conan/conan-local
```

Configure the credentials for the remote. By default, they are `admin:password`:

```bash
conan remote login artifactory admin -p password
```

Upload the customer package:

```bash
conan upload customer -r=artifactory
conan search "*" -r=artifactory
```

Navigate to either `Application -> Artifacts` or `Application -> Packages` (wait for package processing).
