# Software Architecture with C++, Second Edition

Software Architecture with C++, Second Edition, Published by Packt

[return to README](../README.md#development-environment)

To compile the examples, you need the recent versions of [CMake](https://cmake.org/), [Ninja](https://ninja-build.org/),
[Clang](https://clang.llvm.org/) and [Conan 2.0](https://conan.io/).

# The package manager [Homebrew](https://brew.sh/) installation

- [installation](https://docs.brew.sh/Installation)
- [common issues](https://docs.brew.sh/Common-Issues)
- [FAQ](https://docs.brew.sh/FAQ)

```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

## Development tools

Then install these tools with Homebrew

```brew
brew install cmake
brew install ninja
brew install llvm
brew install lld
brew install conan
```

Add these settings to your shell configuration files (.zshrc, .bashrc) for clang and clang++ compilers.
Make sure your IDE's compiler settings use these settings

```
export PATH="$(brew --prefix llvm)/bin:$PATH"

export LDFLAGS="-L$(brew --prefix llvm)/lib -L$(brew --prefix llvm)/lib/c++ -L$(brew --prefix llvm)/lib/unwind -lunwind"
export CPPFLAGS="-I$(brew --prefix llvm)/include"
```

The newer libc++ is used to build software on older macOS systems. The tools are installed in `/usr/local/bin/` and `/usr/local/opt/`

Conan is [integrated](https://docs.conan.io/2/integrations.html) with different IDEs including
[CLion](https://docs.conan.io/2/integrations/clion.html) ([plugin](https://www.jetbrains.com/help/clion/conan-plugin.html)),
[Qt Creator](https://doc.qt.io/qtcreator/creator-project-conan.html) ([plugin](https://doc.qt.io/qtcreator/creator-project-conan.html)) and
[Visual Studio Code](https://code.visualstudio.com/docs/cpp/cmake-quickstart) ([plugin](https://marketplace.visualstudio.com/items?itemName=afri-bit.vsconan))
that support CMake-based projects.

## Docker installation

- [Colima](https://github.com/abiosoft/colima)
- [OrbStack](https://orbstack.dev/)
- [Lima](https://github.com/lima-vm/lima)
- [Rancher Desktop](https://docs.rancherdesktop.io/getting-started/installation/)
- [Docker Desktop](https://docs.docker.com/desktop/setup/install/mac-install/)

## Local Kubernetes installation

- [microk8s](https://microk8s.io/docs/install-macos) (tested)
- [minikube](https://minikube.sigs.k8s.io/docs/)
- [kind](https://kind.sigs.k8s.io/docs/user/quick-start/)
- [Rancher Desktop](https://docs.rancherdesktop.io/ui/preferences/kubernetes/)
- [Docker Desktop](https://docs.docker.com/desktop/features/kubernetes/)

Tools to manage Kubernetes clusters and deploy applications

- [kubectl](https://kubernetes.io/docs/tasks/tools/install-kubectl-windows/)
- [Helm](https://helm.sh/docs/intro/install/)

### Troubleshooting

If you use Conan and dependencies are not compiled in your environment, try configuring the [profiles](https://docs.conan.io/2/reference/config_files/profiles.html).
You can [replace requirements](https://docs.conan.io/2/reference/config_files/profiles.html).
For instance, the settings in `~/.conan2/profiles/default`:

```text
[replace_requires]
libiconv/*: libiconv/1.18
libpq/*: libpq/15.12
```

Configure [build options](https://docs.conan.io/2/reference/config_files/global_conf.html) globally or in your Conan profile.
GCC 15 changes the default language version for C compilation from -std=gnu17 to -std=gnu23 that brakes some Conan recipes.

```text
[conf]
tools.build:cflags=["-std=gnu17"]
```

The development libraries can also be installed with Homebrew.
