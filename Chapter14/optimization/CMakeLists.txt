add_executable(optimization_1 main_1.cpp)
target_link_libraries(optimization_1 PRIVATE benchmark::benchmark)
target_compile_features(optimization_1 PRIVATE cxx_std_20)

add_executable(optimization_2 main_2.cpp)
target_link_libraries(optimization_2 PRIVATE Catch2::Catch2WithMain)
target_compile_features(optimization_2 PRIVATE cxx_std_23)
