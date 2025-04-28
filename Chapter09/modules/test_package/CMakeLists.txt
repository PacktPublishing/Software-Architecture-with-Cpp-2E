cmake_minimum_required(VERSION 3.28)

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
target_compile_features(stores_lib PUBLIC cxx_std_20)
target_link_libraries(stores_lib PUBLIC stores::stores)

add_executable(example example.cpp)
target_compile_features(example PUBLIC cxx_std_20)
target_link_libraries(example stores_lib)
