cmake_minimum_required(VERSION 3.28)

project(Chapter06 LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

list(APPEND CMAKE_PREFIX_PATH "${CMAKE_BINARY_DIR}")

find_package(Microsoft.GSL CONFIG REQUIRED)

add_executable(raii_guards 01_raii_guards.cpp)
target_compile_features(raii_guards PRIVATE cxx_std_11)
target_link_libraries(raii_guards PRIVATE Microsoft.GSL::GSL)

add_executable(copy_move 02_copy_move.cpp)
target_compile_features(copy_move PRIVATE cxx_std_17)

add_executable(rules_of_5_and_0 03_rules_of_5_and_0.cpp)
target_compile_features(rules_of_5_and_0 PRIVATE cxx_std_17)

add_executable(hidden_friend__copy_and_swap 04_hidden_friend__copy_and_swap.cpp)
target_compile_features(hidden_friend__copy_and_swap PRIVATE cxx_std_17)

add_executable(niebloids 05_niebloids.cpp)
target_compile_features(niebloids PRIVATE cxx_std_20)
target_link_libraries(niebloids PRIVATE Microsoft.GSL::GSL)

add_executable(policy-based_design 06_policy-based_design.cpp)
target_compile_features(policy-based_design PRIVATE cxx_std_17)

add_executable(static_polymorphism1 07_static_polymorphism_1.cpp)
target_compile_features(static_polymorphism1 PRIVATE cxx_std_20)

add_executable(static_polymorphism2 07_static_polymorphism_2.cpp)
target_compile_features(static_polymorphism2 PRIVATE cxx_std_23)

add_executable(raii_deducing_this 07_raii_deducing_this.cpp)
target_compile_features(raii_deducing_this PRIVATE cxx_std_23)

add_executable(type_erasure 08_type_erasure.cpp)
target_compile_features(type_erasure PRIVATE cxx_std_20)

add_executable(factory_functions 09_factory_functions.cpp)
target_compile_features(factory_functions PRIVATE cxx_std_17)

add_executable(factory_class 10_factory_class.cpp)
target_compile_features(factory_class PRIVATE cxx_std_20)

add_executable(builder 11_builder.cpp)
target_compile_features(builder PRIVATE cxx_std_23)

add_executable(state_and_visitation 12_state_and_visitation.cpp)
target_compile_features(state_and_visitation PRIVATE cxx_std_23)

add_executable(memory_arenas 13_memory_arenas.cpp)
target_compile_features(memory_arenas PRIVATE cxx_std_20)

add_executable(memory_arena_winking_out 13_memory_arena_winking_out.cpp)
target_compile_features(memory_arena_winking_out PRIVATE cxx_std_20)

add_executable(small_string_optimization 14_small_string_optimization.cpp)
target_compile_features(small_string_optimization PRIVATE cxx_std_11)

add_executable(placement_syntax1 15_placement_syntax1.cpp)
target_compile_features(placement_syntax1 PRIVATE cxx_std_20)

add_executable(placement_syntax2 15_placement_syntax2.cpp)
target_compile_features(placement_syntax2 PRIVATE cxx_std_20)

add_executable(string_cow 15_string_copy_on_write.cpp)
target_compile_features(string_cow PRIVATE cxx_std_98)
