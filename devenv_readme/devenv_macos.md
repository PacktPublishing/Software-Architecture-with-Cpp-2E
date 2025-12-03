# Software Architecture with C++, Second Edition

Software Architecture with C++: Designing Robust C++ Systems with Modern Architectural Practices, Second Edition, published by Packt

[return to README](../README.md#development-environment)

To compile the examples, you need the recent versions of [CMake](https://cmake.org/), [Ninja](https://ninja-build.org/),
[Clang](https://clang.llvm.org/) and [Conan 2.0](https://conan.io/).

# The package manager [Homebrew](https://brew.sh/) installation

- [Installation](https://docs.brew.sh/Installation)
- [Common issues](https://docs.brew.sh/Common-Issues)
- [FAQ](https://docs.brew.sh/FAQ)

```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

To uninstall Homebrew, run the uninstall script:

```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/uninstall.sh)"
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

- [MicroK8s](https://microk8s.io/docs/install-macos)
- [minikube](https://minikube.sigs.k8s.io/docs/)
- [k8s kind](https://kind.sigs.k8s.io/docs/user/quick-start/)
- [Rancher Desktop](https://docs.rancherdesktop.io/ui/preferences/kubernetes/)
- [Docker Desktop](https://docs.docker.com/desktop/features/kubernetes/)
- [Podman Desktop](https://podman-desktop.io/tutorial/running-a-kubernetes-cluster)

Tools to manage Kubernetes clusters and deploy applications

- [kubectl](https://kubernetes.io/docs/tasks/tools/install-kubectl-windows/)
- [Helm](https://helm.sh/docs/intro/install/)

### Troubleshooting

Try deleting the project's build files and recompiling it. It helps if you change Conan recipes because CMake files can cache previous settings.

If you use Conan and dependencies are not compiled in your environment, try to
configure the [profiles](https://docs.conan.io/2/reference/config_files/profiles.html) where
you can [replace requirements](https://docs.conan.io/2/reference/config_files/profiles.html).
For instance, change the settings in `~/.conan2/profiles/default`:

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

Conan can also determine current C and C++ compilers from the CC and CXX environment variables.
For instance, this command overwrites the default profile:

```bash
CC=/usr/bin/clang CXX=/usr/bin/clang++ conan profile detect --force
```

The package manager may not detect compilers correctly, so you need to specify the settings yourself in this case.
