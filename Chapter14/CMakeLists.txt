cmake_minimum_required(VERSION 3.28)

project(
  Chapter14
  VERSION 0.0.1
  LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

list(APPEND CMAKE_PREFIX_PATH "${CMAKE_BINARY_DIR}")
find_package(benchmark REQUIRED)
find_package(nanobench CONFIG REQUIRED)
find_package(doctest REQUIRED)

find_package(libcoro CONFIG REQUIRED)
find_package(Boost REQUIRED)

if(NOT MSVC)
  find_package(coost CONFIG REQUIRED)
endif()

add_subdirectory(coroutines)
add_subdirectory(microbenchmarking/benchmark)
add_subdirectory(microbenchmarking/nanobench)
