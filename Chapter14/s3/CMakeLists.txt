cmake_minimum_required(VERSION 3.28)

project(
  S3
  VERSION 0.0.1
  LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

find_program(CCACHE_PROGRAM ccache)
if(CCACHE_PROGRAM)
  set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CCACHE_PROGRAM}")
endif()

find_package(AWSSDK REQUIRED)
find_package(spdlog REQUIRED)

add_executable(s3 s3.cpp)
target_link_libraries(s3 PRIVATE AWS::aws-sdk-cpp-s3 spdlog::spdlog)
target_compile_features(s3 PRIVATE cxx_std_17)
