add_executable(profiler_1 main_1.cpp)
target_link_libraries(profiler_1 PRIVATE Tracy::TracyClient)
target_compile_features(profiler_1 PRIVATE cxx_std_11)
