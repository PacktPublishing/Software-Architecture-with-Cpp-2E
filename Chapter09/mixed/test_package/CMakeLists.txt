cmake_minimum_required(VERSION 3.28)

project(PackageTest CXX)

list(APPEND CMAKE_PREFIX_PATH "${CMAKE_BINARY_DIR}")

find_package(stores CONFIG REQUIRED)

add_executable(example_hdr example_hdr.cpp)
target_link_libraries(example_hdr stores::stores)

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

add_executable(example_mod example_mod.cpp)
target_compile_features(example_mod PUBLIC cxx_std_20)
target_link_libraries(example_mod stores_lib)
