cmake_minimum_required(VERSION 3.28)

project(
  MinIO
  VERSION 0.0.1
  LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

find_program(CCACHE_PROGRAM ccache)
if(CCACHE_PROGRAM)
  set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CCACHE_PROGRAM}")
endif()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_BINARY_DIR}")

find_package(miniocpp REQUIRED)
find_package(sole REQUIRED)
find_package(spdlog REQUIRED)

add_executable(minio minio.cpp)
target_link_libraries(minio PRIVATE miniocpp::miniocpp sole::sole
                                    spdlog::spdlog)
target_compile_features(minio PRIVATE cxx_std_17)
