cmake_minimum_required(VERSION 3.16)
project(rest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

find_package(Drogon CONFIG REQUIRED)

add_executable(rest main.cpp)
target_link_libraries(rest PRIVATE Drogon::Drogon)

add_custom_command(
  TARGET rest
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory static
          ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/static
  VERBATIM)
