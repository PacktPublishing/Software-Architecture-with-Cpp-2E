function(add_benchmark NAME SOURCE)
  add_executable(${NAME} ${SOURCE})
  target_compile_features(${NAME} PRIVATE cxx_std_23)
  target_link_libraries(${NAME} PRIVATE nanobench::nanobench doctest::doctest)
endfunction()

add_benchmark(nanobench_1 main_1.cpp)
add_benchmark(nanobench_2 main_2.cpp)
add_benchmark(nanobench_3 main_3.cpp)
add_benchmark(nanobench_4 main_4.cpp)
