cmake_minimum_required(VERSION 3.16)
project(mqtt)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

list(APPEND CMAKE_PREFIX_PATH "${CMAKE_BINARY_DIR}")

find_package(PahoMqttCpp REQUIRED)

add_executable(publisher publisher.cpp)
target_link_libraries(publisher PahoMqttCpp::paho-mqttpp3-static)

add_executable(subscriber subscriber.cpp)
target_link_libraries(subscriber PahoMqttCpp::paho-mqttpp3-static)
