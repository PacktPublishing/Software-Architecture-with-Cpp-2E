cmake_minimum_required(VERSION 3.16)
project(thrift)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

find_package(Thrift REQUIRED)

add_executable(server server.cpp gen-cpp/Service.cpp)
target_link_libraries(server PRIVATE thrift::thrift)

add_executable(client client.cpp gen-cpp/Service.cpp)
target_link_libraries(client PRIVATE thrift::thrift)
