# Software Architecture with C++, Second Edition

Software Architecture with C++, Second Edition, Published by Packt

[return to README](../README.md#development-environment)

To compile the examples, you need the recent versions of [CMake](https://cmake.org/), [Ninja](https://ninja-build.org/),
either [Clang](https://clang.llvm.org/) or [GCC](https://gcc.gnu.org/), and [Conan 2.0](https://conan.io/).
Of course for this purpose, you can use package repositories of your Linux distribution,
[Snapcraft](https://snapcraft.io/), [Flathub](https://flathub.org/), [AppImageHub](https://www.appimagehub.com/browse)
or an IDE with bundled tools.

## The package manager [Homebrew](https://brew.sh/) installation

- [installation](https://docs.brew.sh/Homebrew-on-Linux)
- [common issues](https://docs.brew.sh/Common-Issues)
- [FAQ](https://docs.brew.sh/FAQ)

```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

Add these settings to your shell configuration files (`.zshrc`, `.bashrc`) to run [Homebrew on Linux](https://docs.brew.sh/Homebrew-on-Linux)

```
[ -d /home/linuxbrew/.linuxbrew ] && eval $(/home/linuxbrew/.linuxbrew/bin/brew shellenv)
```

## Development tools

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
The compilers are installed in `/home/linuxbrew/.linuxbrew/bin/`

Conan is [integrated](https://docs.conan.io/2/integrations.html) with different IDEs including
[CLion](https://docs.conan.io/2/integrations/clion.html) ([plugin](https://www.jetbrains.com/help/clion/conan-plugin.html)),
[Qt Creator](https://doc.qt.io/qtcreator/creator-project-conan.html) ([plugin](https://doc.qt.io/qtcreator/creator-project-conan.html)) and
[Visual Studio Code](https://code.visualstudio.com/docs/cpp/cmake-quickstart) ([plugin](https://marketplace.visualstudio.com/items?itemName=afri-bit.vsconan))
that support CMake-based projects.

## Docker installation

- [Ubuntu](https://docs.docker.com/desktop/setup/install/linux/ubuntu/)
- [Debian](https://docs.docker.com/desktop/setup/install/linux/debian/)
- [Fedora](https://docs.docker.com/desktop/setup/install/linux/fedora/)
- [Arch](https://docs.docker.com/desktop/setup/install/linux/archlinux/)
- [RHEL](https://docs.docker.com/desktop/setup/install/linux/rhel/)
- [Rancher Desktop](https://docs.rancherdesktop.io/getting-started/installation/)
- [Docker Desktop](https://docs.docker.com/desktop/setup/install/linux/)

## Local Kubernetes installation

- [microk8s](https://microk8s.io/docs/getting-started) (tested)
- [minikube](https://minikube.sigs.k8s.io/docs/)
- [kind](https://kind.sigs.k8s.io/docs/user/quick-start/)
- [K3s](https://docs.k3s.io/installation)
- [Rancher Desktop](https://docs.rancherdesktop.io/ui/preferences/kubernetes/)
- [Docker Desktop](https://docs.docker.com/desktop/features/kubernetes/)

Tools to manage Kubernetes clusters and deploy applications

- [kubectl](https://kubernetes.io/docs/tasks/tools/install-kubectl-windows/)
- [Helm](https://helm.sh/docs/intro/install/)
