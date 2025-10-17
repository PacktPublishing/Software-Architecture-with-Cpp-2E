cmake_minimum_required(VERSION 3.16)
project(rabbitmq)

set(CMAKE_CXX_STANDARD 17)

find_package(amqpcpp REQUIRED)
find_package(Libevent REQUIRED)

add_executable(producer producer.cpp)
target_link_libraries(producer amqpcpp libevent::libevent)

add_executable(consumer consumer.cpp)
target_link_libraries(consumer amqpcpp libevent::libevent)
