cmake_minimum_required(VERSION 3.15)

project(
  Redis
  VERSION 0.0.1
  LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

find_program(CCACHE_PROGRAM ccache)
if(CCACHE_PROGRAM)
  set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CCACHE_PROGRAM}")
endif()

find_package(redis++ REQUIRED)

add_executable(redis_client redis.cpp)
target_compile_features(redis_client PRIVATE cxx_std_17)
target_compile_options(redis_client PRIVATE "${BASE_COMPILE_FLAGS}")
target_link_libraries(redis_client PRIVATE redis++::redis++_static)
