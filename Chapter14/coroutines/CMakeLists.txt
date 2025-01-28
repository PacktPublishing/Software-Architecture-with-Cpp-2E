add_executable(coroutines_1 main_1.cpp)
target_link_libraries(coroutines_1 PRIVATE libcoro::libcoro)
target_compile_features(coroutines_1 PRIVATE cxx_std_23)

add_executable(coroutines_2 main_2.cpp)
target_link_libraries(coroutines_2 PRIVATE Boost::cobalt)
target_compile_features(coroutines_2 PRIVATE cxx_std_23)

if(NOT MSVC)
  add_executable(coroutines_3 main_3.cpp)
  target_link_libraries(coroutines_3 PRIVATE coost::co)
  target_compile_features(coroutines_3 PRIVATE cxx_std_23)
endif()
