# Software Architecture with C++, Second Edition

Software Architecture with C++, Second Edition, Published by Packt

[return to README](../README.md#development-environment)

To compile the examples, you need the recent versions of [CMake](https://cmake.org/), [Ninja](https://ninja-build.org/),
either [Clang](https://clang.llvm.org/) or [GCC](https://gcc.gnu.org/), and [Conan 2.0](https://conan.io/).
Of course for this purpose, you can use package repositories of your Linux distribution,
[Snapcraft](https://snapcraft.io/), [Flathub](https://flathub.org/), [AppImageHub](https://www.appimagehub.com/browse)
or an IDE with bundled tools.

Install the package manager [Homebrew](https://brew.sh/)

- [installation](https://docs.brew.sh/Installation)
- [common issues](https://docs.brew.sh/Common-Issues)
- [FAQ](https://docs.brew.sh/FAQ)

```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

Add these settings to your shell configuration files (`.zshrc`, `.bashrc`) to run [Homebrew on Linux](https://docs.brew.sh/Homebrew-on-Linux)

```
[ -d /home/linuxbrew/.linuxbrew ] && eval $(/home/linuxbrew/.linuxbrew/bin/brew shellenv)
```

Then install these tools with Homebrew

```brew
brew install cmake
brew install ninja
brew install gcc
brew install gdb
brew install llvm
brew install lld
brew install conan
```

Be careful that `/usr/bin/gcc` and `/usr/bin/g++` are the system compilers, but not from Homebrew.
The tools are installed in `/home/linuxbrew/.linuxbrew/bin/`

Conan is [integrated](https://docs.conan.io/2/integrations.html) with different IDEs including
[CLion](https://docs.conan.io/2/integrations/clion.html) ([plugin](https://www.jetbrains.com/help/clion/conan-plugin.html)),
[Qt Creator](https://doc.qt.io/qtcreator/creator-project-conan.html) ([plugin](https://doc.qt.io/qtcreator/creator-project-conan.html)) and
[Visual Studio Code](https://code.visualstudio.com/docs/cpp/cmake-quickstart) ([plugin](https://marketplace.visualstudio.com/items?itemName=afri-bit.vsconan))
that support CMake-based projects.
