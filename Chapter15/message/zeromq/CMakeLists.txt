cmake_minimum_required(VERSION 3.16)
project(zeromq)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

list(APPEND CMAKE_PREFIX_PATH "${CMAKE_BINARY_DIR}")

find_package(ZeroMQ REQUIRED)

add_executable(publisher publisher.cpp)
target_link_libraries(publisher libzmq-static)

add_executable(subscriber subscriber.cpp)
target_link_libraries(subscriber libzmq-static)
