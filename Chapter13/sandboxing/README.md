# Software Architecture with C++, Second Edition

Software Architecture with C++: Designing Robust C++ Systems with Modern Architectural Practices, Second Edition, published by Packt

## Chapter 13: Security in Code and Deployment

### Prerequisites

Install the following software:

- CMake 3.16
- Cheerp toolchain

[Cheerp](https://cheerp.io/docs/overview) is a compiler for Web applications compiling C/C++ to WebAssembly and JavaScript

#### Installation

##### [Installing Cheerp on Linux](https://cheerp.io/docs/getting-started/installation#installing-cheerp-on-linux)

There are several options:

- [Ubuntu](https://cheerp.io/docs/getting-started/installation#ubuntu):
  [packages](https://launchpad.net/~leaningtech-dev/+archive/ubuntu/cheerp-ppa) were published up to Ubuntu 22.04 (Jammy Jellyfish)
- [Arch Linux](https://cheerp.io/docs/getting-started/installation#arch): the [AUR](https://aur.archlinux.org/packages/cheerp-git) package was published in 2024
- [Building from source](https://cheerp.io/docs/building-from-source/linux): the compiler is supported and developed
- [Developing inside a container](https://containers.dev/): [CLion](https://www.jetbrains.com/help/clion/remote-development.html),
  [Visual Studio](https://devblogs.microsoft.com/cppblog/dev-containers-for-c-in-visual-studio/),
  [Visual Studio Code](https://code.visualstudio.com/docs/devcontainers/containers) and [the others](https://containers.dev/supporting)

In addition, the container images can be independently built from the directory `.devcontainer`:

```bash
docker build -t cheerp .
```

And used to compile applications in running containers, which requires mounting the source code directory:

```bash
docker run --rm -v $(pwd):/src -u $(id -u):$(id -g) cheerp clang++ main.cpp -o app.js
```

##### [Installing Cheerp on Windows](https://cheerp.io/docs/getting-started/installation#installing-cheerp-on-windows)

Download the latest graphical installer from [GitHub](https://github.com/leaningtech/cheerp-meta/releases)
and follow the installation wizard. The default installation path is currently the only supported one.

##### [Installing Cheerp on macOS](https://cheerp.io/docs/getting-started/installation#installing-cheerp-on-macos)

Download the DMG image for macOS from [GitHub](https://github.com/leaningtech/cheerp-meta/releases) and install it
by opening the image and drag-and-dropping Cheerp into the /Applications directory.

The binary is not signed so you may need to run the following to stop Gatekeeper from blocking the executable:

```bash
sudo xattr -d com.apple.quarantine /Applications/cheerp/bin/
```

#### Running the web app

Due to security reasons, web browsers do not allow local JavaScript files to run.
Instead, run an HTTP server from the build directory and open the page there.

This requires [Node.js](https://nodejs.org/en/download/) to be installed:

```bash
npx http-server
```

Or [Python](https://www.python.org/downloads/):

```bash
python -m http.server 8000
```

#### [Building a CMake project using Cheerp](https://cheerp.io/docs/guides/build-systems/cmake)

The toolchain includes clang (C compiler) and clang++ (C++ compiler).

As an option, CLion supports [Docker toolchains](https://www.jetbrains.com/help/clion/clion-toolchains-in-docker.html#create-docker-toolchain).
Therefore, if you build a container image with Cheerp as presented above, then such an image can be used to compile applications
and even navigate through the source code of Cheerp development libraries from the IDE.
