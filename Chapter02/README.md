# Software Architecture with C++, Second Edition

Software Architecture with C++: Designing Robust C++ Systems with Modern Architectural Practices, Second Edition, published by Packt

## Chapter 2: Architectural Styles

### Prerequisites

Install the following software:

- CMake 3.28
- GCC 15, Clang 20, MSVC 19.50

The C++ compiler in your IDE and the Conan profile must be compatible to compile examples from the IDE.

Assuming you're on Linux or using WSL. The examples are developed on Linux, but their compilation and
functionality are also tested on macOS and Windows.

### Building

To build the project using your default compiler run:

```bash
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build .
```

If GCC 15 is not your default compiler, you can tell CMake to use it with the `CMAKE_CXX_COMPILER` flag.
Replace the first invocation above with:

```bash
cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_COMPILER=`which g++-15`
```
