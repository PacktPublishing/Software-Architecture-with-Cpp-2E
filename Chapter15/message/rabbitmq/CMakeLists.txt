cmake_minimum_required(VERSION 3.16)
project(rabbitmq)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

find_package(amqpcpp REQUIRED)
find_package(Libevent REQUIRED)

add_executable(producer producer.cpp)
target_link_libraries(producer amqpcpp libevent::libevent)

add_executable(consumer consumer.cpp)
target_link_libraries(consumer amqpcpp libevent::libevent)
