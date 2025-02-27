cmake_minimum_required(VERSION 3.28...3.31)

project(
  Customer
  VERSION 0.0.1
  LANGUAGES CXX)

find_program(CCACHE_PROGRAM ccache)
if(CCACHE_PROGRAM)
  set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CCACHE_PROGRAM}")
endif()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_BINARY_DIR}")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")
set(BUILD_SHARED_LIBS OFF)

if(NOT MSVC)
  set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
else()
  set(CMAKE_FIND_LIBRARY_SUFFIXES ".lib")
endif()

find_package(Drogon REQUIRED)

find_package(opentelemetry-cpp REQUIRED)
find_package(gRPC REQUIRED)

include(CommonCompileFlags)

add_subdirectory(src/customer)
