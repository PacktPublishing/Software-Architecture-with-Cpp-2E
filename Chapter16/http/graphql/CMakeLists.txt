cmake_minimum_required(VERSION 3.27)
project(graphql)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_BINARY_DIR}")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

find_package(Drogon REQUIRED)

include(CPM)

# cmake-format: off
CPMAddPackage(
        NAME RapidJSON
        GITHUB_REPOSITORY Tencent/rapidjson
        GIT_TAG 24b5e7a8b27f42fa16b96fc70aade9106cf7102f
        EXCLUDE_FROM_ALL
        OPTIONS "RAPIDJSON_BUILD_DOC OFF" "RAPIDJSON_BUILD_EXAMPLES OFF" "RAPIDJSON_BUILD_TESTS OFF")
# cmake-format: on

find_package(RapidJSON CONFIG REQUIRED)

# TODO: RapidJSON does not provide a proper config file, but cppgraphqlgen
# requires this variable to be set.
set(RAPIDJSON_INCLUDE_DIRS ${RapidJSON_SOURCE_DIR}/include)

# cmake-format: off
CPMAddPackage(
  NAME cppgraphqlgen
  GITHUB_REPOSITORY microsoft/cppgraphqlgen
  GIT_TAG v4.5.9
  VERSION 4.5.9
  EXCLUDE_FROM_ALL
  OPTIONS "GRAPHQL_BUILD_TESTS OFF" "GRAPHQL_UPDATE_SAMPLES OFF" "GRAPHQL_BUILD_HTTP_SAMPLE OFF")
# cmake-format: on

find_package(cppgraphqlgen CONFIG REQUIRED)

add_subdirectory(server)
add_subdirectory(client)
