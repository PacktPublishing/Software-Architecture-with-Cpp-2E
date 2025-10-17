cmake_minimum_required(VERSION 3.27)
project(kafka)

set(CMAKE_CXX_STANDARD 17)

find_package(RdKafka REQUIRED)
find_package(modern-cpp-kafka REQUIRED)

add_executable(producer producer.cpp)
target_link_libraries(producer PRIVATE RdKafka::rdkafka++
                                       modern-cpp-kafka::modern-cpp-kafka)

add_executable(consumer consumer.cpp)
target_link_libraries(consumer PRIVATE RdKafka::rdkafka++
                                       modern-cpp-kafka::modern-cpp-kafka)
