cmake_minimum_required(VERSION 3.28)

project(
  Chapter05
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
list(APPEND CMAKE_PREFIX_PATH "${PROJECT_BINARY_DIR}")

find_package(Microsoft.GSL CONFIG REQUIRED)

include(CommonCompileFlags)

add_library(apis INTERFACE)
target_include_directories(apis INTERFACE src/apis)

add_executable(declarative src/apis/declarative.cpp)
target_compile_features(declarative PUBLIC cxx_std_20)

add_executable(base src/1_base.cpp)
target_link_libraries(base PRIVATE Microsoft.GSL::GSL)
target_compile_features(base PRIVATE cxx_std_20)
target_compile_options(base PRIVATE ${BASE_COMPILE_FLAGS})

add_executable(ranges1 src/2_ranges_part_1.cpp)
target_link_libraries(ranges1 PRIVATE Microsoft.GSL::GSL)
target_compile_features(ranges1 PRIVATE cxx_std_20)
target_compile_options(ranges1 PRIVATE ${BASE_COMPILE_FLAGS})

add_executable(ranges2 src/3_ranges_part_2.cpp)
target_link_libraries(ranges2 PRIVATE Microsoft.GSL::GSL)
target_compile_features(ranges2 PRIVATE cxx_std_20)
target_compile_options(ranges2 PRIVATE ${BASE_COMPILE_FLAGS})

add_executable(constexpr src/4_constexpr.cpp)
target_compile_features(constexpr PRIVATE cxx_std_20)
target_compile_options(constexpr PRIVATE ${BASE_COMPILE_FLAGS})

add_executable(concepts src/5_concepts.cpp)
target_link_libraries(concepts PRIVATE Microsoft.GSL::GSL)
target_compile_features(concepts PRIVATE cxx_std_20)
target_compile_options(concepts PRIVATE ${BASE_COMPILE_FLAGS})

add_executable(monadic_optional src/6_monadic_optional.cpp)
target_compile_features(monadic_optional PRIVATE cxx_std_23)
target_compile_options(monadic_optional PRIVATE ${BASE_COMPILE_FLAGS})

add_executable(monadic_expected src/6_monadic_expected.cpp)
target_compile_features(monadic_expected PRIVATE cxx_std_23)
target_compile_options(monadic_expected PRIVATE ${BASE_COMPILE_FLAGS})

add_executable(pointers src/7_pointers.cpp)
target_compile_features(pointers PRIVATE cxx_std_20)
target_compile_options(pointers PRIVATE ${BASE_COMPILE_FLAGS})

add_executable(raii src/8_raii.cpp)
target_compile_features(raii PRIVATE cxx_std_20)
target_compile_options(raii PRIVATE ${BASE_COMPILE_FLAGS})
