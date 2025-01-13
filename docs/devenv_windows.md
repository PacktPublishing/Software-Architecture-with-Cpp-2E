# Software Architecture with C++, Second Edition

Software Architecture with C++, Second Edition, Published by Packt

[return to README](../README.md#development-environment)

To compile the examples, you need the recent versions of [CMake](https://cmake.org/), [Ninja](https://ninja-build.org/),
either [Clang](https://clang.llvm.org/) or [MSVC compiler](https://visualstudio.microsoft.com/downloads/), and [Conan 2.0](https://conan.io/).
Of course for this purpose, you can use the package managers such as [Chocolatey](https://chocolatey.org/),
[winget.run](https://winget.run/), and an IDE with bundled tools.

The first option is to download the tools and install them:

- [CMake](https://cmake.org/download/)
- [Ninja](https://ninja-build.org/)
- [Conan](https://conan.io/downloads)
- [Clang](https://releases.llvm.org/)

The second option is the package manager [Chocolatey](https://chocolatey.org/install);

```
choco install cmake
choco install ninja
choco install llvm
choco install conan
```

The third option is the package manager [winget.run](https://winget.run/):

```
winget install -e --id Kitware.CMake
winget install -e --id Ninja-build.Ninja
winget install -e --id LLVM.LLVM
winget install -e --id JFrog.Conan
```

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
Enter this parameter as the CMake argument `-DCMAKE_PROJECT_TOP_LEVEL_INCLUDES="psth_to/conan_provider.cmake"`in the field `CMake command arguments:`.
Your configuration will be saved in [CMakeSettings.json](https://learn.microsoft.com/en-us/cpp/build/cmake-presets-vs?view=msvc-170).
