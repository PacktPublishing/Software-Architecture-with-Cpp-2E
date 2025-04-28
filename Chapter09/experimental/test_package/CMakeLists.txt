cmake_minimum_required(VERSION 4.0.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "a9e1cf81-9932-4810-974b-6eccaf14e457")
set(CMAKE_CXX_MODULE_STD 1)

project(PackageTest CXX)

list(APPEND CMAKE_PREFIX_PATH "${CMAKE_BINARY_DIR}")

find_package(stores CONFIG REQUIRED)

string(TOUPPER "${CMAKE_BUILD_TYPE}" config_suffix)
set(stores_lib_base_dir ${stores_LIB_DIRS_${config_suffix}})
set(stores_lib_files
    "${stores_lib_base_dir}/customer.cppm"
    "${stores_lib_base_dir}/merchant.cppm" "${stores_lib_base_dir}/store.cppm"
    "${stores_lib_base_dir}/store_item.cppm")

add_library(stores_lib)
target_sources(
  stores_lib PUBLIC FILE_SET CXX_MODULES BASE_DIRS ${stores_lib_base_dir} FILES
                    ${stores_lib_files})
target_compile_features(stores_lib PUBLIC cxx_std_23)
target_link_libraries(stores_lib PUBLIC stores::stores)

add_executable(example example.cpp)
target_compile_features(example PUBLIC cxx_std_23)
target_link_libraries(example stores_lib)
