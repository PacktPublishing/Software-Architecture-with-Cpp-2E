# Software Architecture with C++, Second Edition

Software Architecture with C++, Second Edition, Published by Packt

## Chapter 1: Importance of Software Architecture and Principles of Great Design

### Prerequisites

Install the following software:

- CMake 3.28
- GCC 14

### Building

To build the project using your default compiler run:

```bash
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build .
```

If GCC 14 is not your default compiler, you can tell CMake to use it with the `CMAKE_CXX_COMPILER` flag.
Replace the first invocation above with:

```bash
cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_COMPILER=`which g++-14`
```
