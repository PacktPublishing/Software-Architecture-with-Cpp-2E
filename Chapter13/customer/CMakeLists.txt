cmake_minimum_required(VERSION 3.28...3.31)

project(
  Customer
  VERSION 0.0.1
  LANGUAGES CXX)

find_program(CCACHE_PROGRAM ccache)
if(CCACHE_PROGRAM)
  set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CCACHE_PROGRAM}")
endif()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_BINARY_DIR}")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

find_package(Drogon REQUIRED)

# TODO: provide Drogon_BIN_DIR
find_program(DROGON_EXECUTABLE drogon_ctl ${Drogon_INCLUDE_DIR}/../bin/)

find_package(inja REQUIRED)

include(CommonCompileFlags)

add_subdirectory(src/customer)
