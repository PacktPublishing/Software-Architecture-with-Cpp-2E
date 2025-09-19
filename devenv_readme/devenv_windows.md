# Software Architecture with C++, Second Edition

Software Architecture with C++: Designing Robust C++ Systems with Modern Architectural Practices, Second Edition, published by Packt

[return to README](../README.md#development-environment)

To compile the examples, you need the recent versions of [CMake](https://cmake.org/), [Ninja](https://ninja-build.org/),
either [MSVC compiler](https://visualstudio.microsoft.com/downloads/) or [Clang](https://clang.llvm.org/), and [Conan 2.0](https://conan.io/).
Of course for this purpose, you can use the package managers such as [Chocolatey](https://chocolatey.org/),
[winget.run](https://winget.run/), and an IDE with bundled tools.

## Development tools

The first option is to download the tools and install them:

- [CMake](https://cmake.org/download/)
- [Ninja](https://ninja-build.org/)
- [Conan](https://conan.io/downloads)
- [MSVC compiler](https://visualstudio.microsoft.com/downloads/)
- [Clang](https://releases.llvm.org/)

The second option is the package manager [Chocolatey](https://chocolatey.org/install) ([packages](https://community.chocolatey.org/packages)):

```
choco install cmake
choco install ninja
choco install llvm
choco install conan
```

The third option is the package manager [winget.run](https://winget.run/) or [winstall](https://winstall.app/)([apps](https://winstall.app/apps)):

```
winget install -e --id Kitware.CMake
winget install -e --id Ninja-build.Ninja
winget install -e --id LLVM.LLVM
winget install -e --id JFrog.Conan
```

The fourth option is the package manager [Scoop](https://scoop.sh/#/) ([apps](https://scoop.sh/#/apps)):

```
scoop bucket add main

scoop install main/cmake
scoop install main/ninja
scoop install main/llvm
scoop install main/conan

scoop install main/mingw
```

The fifth option is [MSYS2](https://www.msys2.org/), a software distribution and development platform for Windows,
that provides a Unix-like environment ([introduction](https://www.msys2.org/wiki/MSYS2-introduction/),
[environments](https://www.msys2.org/docs/environments/), [packages](https://packages.msys2.org/packages/):

Update MSYS2 with following command:

```
pacman -Syu
```

Install the necessary tools (for instance `UCRT64`. The other environments are `CLANG64`, `CLANGARM64`, `MINGW64`, `MSYS`):

```
pacman -S base-devel cmake ninja mingw-w64-ucrt-x86_64-python-conan git
pacman -S mingw-w64-ucrt-x86_64-toolchain
pacman -S mingw-w64-ucrt-x86_64-gdb
```

Optional: Add executables to your Windows PATH:

```
C:\msys64\ucrt64\bin
C:\msys64\usr\bin
```

Libraries and include files can be found in two places:

```
C:\msys64\ucrt64\bin
C:\msys64\ucrt64\lib
C:\msys64\ucrt64\include
C:\msys64\usr\bin
C:\msys64\usr\lib
C:\msys64\usr\include
```

## Conan

Conan is [integrated](https://docs.conan.io/2/integrations.html) with different IDEs including
[CLion](https://docs.conan.io/2/integrations/clion.html) ([plugin](https://www.jetbrains.com/help/clion/conan-plugin.html)),
[Qt Creator](https://doc.qt.io/qtcreator/creator-project-conan.html) ([plugin](https://doc.qt.io/qtcreator/creator-project-conan.html)),
[Visual Studio Code](https://code.visualstudio.com/docs/cpp/cmake-quickstart) ([plugin](https://marketplace.visualstudio.com/items?itemName=afri-bit.vsconan)) and
[Visual Studio](https://docs.conan.io/2/integrations/visual_studio.html) ([plugin](https://marketplace.visualstudio.com/items?itemName=conan-io.conan-vs-extension))
that support CMake-based projects.

[CLion](https://www.jetbrains.com/help/clion/how-to-switch-compilers-in-clion.html) and [Qt Creator](https://doc.qt.io/qtcreator/creator-tool-chains.html) can compile projects with bundled tools or MSVC compiler on Windows.

Conan and CMake in Visual Studio:

[Note](https://docs.conan.io/2/integrations/visual_studio.html)

> The Visual Studio extension is only compatible with C/C++ projects based on MSBuild.
> It will not work with CMake-based projects or projects using other technologies.
> For CMake-based projects, please refer to the cmake-conan dependency provider.

As of the version 3.24, CMake has support for [dependency providers](https://cmake.org/cmake/help/latest/guide/using-dependencies/index.html#dependency-providers).
Clone cmake-conan Git repo or just copy [conan_provider.cmake](https://raw.githubusercontent.com/conan-io/cmake-conan/refs/heads/develop2/conan_provider.cmake) somewhere:

```
git clone https://github.com/conan-io/cmake-conan.git
```

Open the CMake settings editor to [customize build settings](https://learn.microsoft.com/en-us/cpp/build/customize-cmake-settings?view=msvc-170), select the Configuration drop-down and choose `Manage configurations...`.
Specify the path to [conan_provider.cmake](https://github.com/conan-io/cmake-conan/blob/develop2/conan_provider.cmake) in the variable `CMAKE_PROJECT_TOP_LEVEL_INCLUDES`.
Enter this parameter as the CMake argument `-DCMAKE_PROJECT_TOP_LEVEL_INCLUDES="path_to/conan_provider.cmake"`in the field `CMake command arguments:`.
Your configuration will be saved in [CMakeSettings.json](https://learn.microsoft.com/en-us/cpp/build/cmake-presets-vs?view=msvc-170).

## Docker installation

- [Rancher Desktop](https://docs.rancherdesktop.io/getting-started/installation/)
- [Docker Desktop](https://docs.docker.com/desktop/setup/install/windows-install/)

## Local Kubernetes installation

- [microk8s](https://microk8s.io/docs/install-windows) or [WSL2](https://microk8s.io/docs/install-wsl2)
- [minikube](https://minikube.sigs.k8s.io/docs/)
- [kind](https://kind.sigs.k8s.io/docs/user/quick-start/)
- [Rancher Desktop](https://docs.rancherdesktop.io/ui/preferences/kubernetes/)
- [Docker Desktop](https://docs.docker.com/desktop/features/kubernetes/)

Tools to manage Kubernetes clusters and deploy applications

- [kubectl](https://kubernetes.io/docs/tasks/tools/install-kubectl-windows/)
- [Helm](https://helm.sh/docs/intro/install/)

### Troubleshooting

Try deleting the project's build files and recompiling it. It helps if you change Conan recipes because CMake files can cache previous settings.

If you use Conan and dependencies are not compiled in your environment, try to
configure the [profiles](https://docs.conan.io/2/reference/config_files/profiles.html) where
you can [replace requirements](https://docs.conan.io/2/reference/config_files/profiles.html).
For instance, change the settings in `%USERPROFILE%\.conan2\profiles\default`:

```text
[replace_requires]
libiconv/*: libiconv/1.18
libpq/*: libpq/15.12
```

Configure [build options](https://docs.conan.io/2/reference/config_files/global_conf.html) globally or in your Conan profile.
For example, GCC 15 changes the default language version for C compilation from -std=gnu17 to -std=gnu23 that brakes some Conan recipes.

In this case, set the options such as the cstd version in the profile section `[settings]`:

```text
compiler.cstd=gnu17
```

Or set the environment variables `CXXFLAGS` and `CFLAGS`:

```text
[conf]
tools.build:cflags=["-std=gnu17"]
```

Conan can use a compiler other than the [auto-detected](https://docs.conan.io/2/reference/tools/cmake/cmaketoolchain.html#conan-cmake-toolchain-conf) one:

```text
[conf]
tools.cmake.cmaketoolchain:generator=Ninja
tools.build:compiler_executables={"c":"/usr/bin/gcc","cpp":"/usr/bin/g++"}
```
