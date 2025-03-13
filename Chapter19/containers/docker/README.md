# Software Architecture with C++, Second Edition

Software Architecture with C++, Second Edition, Published by Packt

## Chapter 19: Containers

#### Docker

```bash
docker build -t basic -f basic.Dockerfile .
docker build -t compile -f compile.Dockerfile .
docker build -t multi-stage -f multi-stage.Dockerfile .
docker build -t scratch -f scratch.Dockerfile .
```

After you build the container image, you should be able to list it with `docker images`, the new image should be listed there.

The `compile` and `multi-stage` examples require a copy of C++ sources present in the current directory.
The `scratch` example requires binary to be present in the working directory.

To build a static binary, you may use:

```bash
rm -rf ./build/ && mkdir build && cd build
conan install .. --build=missing -s:a build_type=Release -s:a compiler=gcc -s:a compiler.cppstd=gnu20 -of .
cmake .. -G Ninja -DCMAKE_BUILD_TYPE=Release -DCMAKE_EXE_LINKER_FLAGS="-static" -DBUILD_SHARED_LIBS=OFF -DCMAKE_FIND_LIBRARY_SUFFIXES=".a"
cmake --build .
```

## Troubleshooting

**Important**: The official Ubuntu Docker image are published for several platforms,
but obviously not for windows/amd64 or windows/arm64:

- linux/amd64
- linux/arm/v7
- linux/arm64/v8
- linux/ppc64le
- linux/riscv64
- linux/s390x

`basic`, `compile` and `multi-stage` have no external dependencies except C++ sources.
But `scratch` depends on the artifact `customer` that has to be compiled for a target platform.

[Development Containers](https://containers.dev) are used to develop inside containers.
`customer/.devcontainer/devcontainer.json` is an example of such a Docker image created from scratch.
IDEs in particular `Visual Studio Code`, `Visual Studio` and `IntelliJ IDEA` support this feature.

```bash
docker build -t basic -f basic.Dockerfile --platform linux/amd64 .
docker build -t compile -f compile.Dockerfile --platform linux/ppc64le .
docker build -t multi-stage -f multi-stage.Dockerfile --platform linux/arm64 .
docker build -t scratch -f scratch.Dockerfile --platform linux/riscv64 .
```

In fact, you can build a development image yourself. For instance, by using `customer/.devcontainer/Dockerfile`.
Go to the directory containing this Dockerfile and run:

```bash
docker build -t devcontainer .
```

Or choose platforms explicitly (for example `linux/amd64` and `linux/arm64`):

```bash
docker build -t devcontainer --platform linux/amd64,linux/arm64 .
```

```bash
docker buildx build --platform linux/amd64,linux/arm64 --tag devcontainer .
```

This is an experimental feature. List the images:

```bash
docker image ls --tree devcontainer
```

You can compile a C++ application in a container or just execute programs from the image.
Don't forget to mount host directories to a container.

Run this command in the directory containing the `customer` project and
apply the recipe above to build the static binary in a running container.
Press Ctrl^D or type `exit` to exit.

```bash
docker run --rm -ti -v ./:/root/customer -w /root/customer/ devcontainer
```

This command mounts the current host directory to the container and changes the working directory.
The executable file `customer` will be in `./build/bin` if your apply the recipe.

Or choose a platform explicitly (`linux/arm64` in our example) if an image for the platform was built:

```bash
docker run --rm -ti -v ./:/root/customer -w /root/customer/ --platform linux/arm64 devcontainer
```

Elegantly simple. That's all Folks!
