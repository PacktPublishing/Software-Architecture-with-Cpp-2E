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
