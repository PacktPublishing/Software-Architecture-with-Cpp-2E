cmake_minimum_required(VERSION 3.27)
project(kafka)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

list(APPEND CMAKE_PREFIX_PATH "${CMAKE_BINARY_DIR}")

find_package(RdKafka REQUIRED)
find_package(modern-cpp-kafka REQUIRED)

add_executable(producer producer.cpp)
target_link_libraries(producer PRIVATE RdKafka::rdkafka++
                                       modern-cpp-kafka::modern-cpp-kafka)

add_executable(consumer consumer.cpp)
target_link_libraries(consumer PRIVATE RdKafka::rdkafka++
                                       modern-cpp-kafka::modern-cpp-kafka)
