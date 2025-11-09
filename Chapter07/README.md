# Software Architecture with C++, Second Edition

Software Architecture with C++: Designing Robust C++ Systems with Modern Architectural Practices, Second Edition, published by Packt

## Chapter 7: Building and Packaging

### Prerequisites

Install the following software:

- CMake 3.28
- Conan 2
- GCC 15

For optional packaging with CPack:

- dpkg build tools: [dh_make](https://manpages.ubuntu.com/manpages/trusty/man8/dh_make.8.html) and [dpkg-buildpackage](https://manpages.ubuntu.com/manpages/trusty/man1/dpkg-buildpackage.1.html) to assemble DEB packages
- rpm build tools: [rpmbuild](https://manpages.ubuntu.com/manpages/trusty/man8/rpmbuild.8.html) to assemble RPM packages
- [linuxdeploy](https://github.com/linuxdeploy/linuxdeploy) to assemble AppImages

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

### Testing

To run tests from each of the projects, cd into their respective build directory, and then simply run `ctest`.

### Installing

In the build directory, run `cmake --install .` to install the software into `${CMAKE_PREFIX_PATH}`. If no prefix is
given, it will install system-wide. To change this, add `-DCMAKE_INSTALL_PREFIX=/path/to/install/to` to your cmake
invocation.

### Packaging

In the build directory, run `cpack`. Simple as that. Assuming you're running on a system supporting DEB and RPM packages,
you'll get a .tar.gz file, a .zip file, a .deb and .rpm packages, and an AppImage executable.

### Troubleshooting

Windows Firewall can block connections to the IP address 0.0.0.0 therefore set 127.0.0.1 in customer/src/customer/main.cpp
as a workaround or allow connections to that address on the host.

AppImages require [FUSE](https://github.com/AppImage/AppImageKit/wiki/FUSE). Package building may fail
due to Linux application security systems such as AppArmor and SELinux.
[fusermount3](https://man.archlinux.org/man/fusermount3.1.en) mounts and unmount [FUSE filesystems](https://wiki.gentoo.org/wiki/Filesystem_in_Userspace/en) in userspace.
This happened after the release of Ubuntu 25.10, where [Flatpak](https://bugs.launchpad.net/ubuntu/+source/flatpak/+bug/2122161/comments/5) packages stopped working.

Temporary workaround to be able to use Flatpak on 25.10 is to disable the Apparmor profile for [fusermount3](https://man.archlinux.org/man/fusermount3.1.en):

```bash
sudo ln -s /etc/apparmor.d/fusermount3 /etc/apparmor.d/disable/
sudo apparmor_parser -R /etc/apparmor.d/fusermount3
```

To later re-enable the profile:

```bash
$ sudo rm /etc/apparmor.d/disable/fusermount3
$ cat /etc/apparmor.d/fusermount3 | sudo apparmor_parser -a
```
