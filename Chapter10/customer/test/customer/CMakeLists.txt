add_executable(catch2tests catch.cpp)
target_link_libraries(catch2tests PRIVATE tradefair::libcustomer Catch2::Catch2)
target_compile_options(catch2tests PRIVATE ${BASE_COMPILE_FLAGS})
catch_discover_tests(catch2tests)

add_executable(gtests gtest.cpp)
target_link_libraries(gtests PRIVATE tradefair::libcustomer GTest::gtest_main)
target_compile_options(gtests PRIVATE ${BASE_COMPILE_FLAGS})
gtest_discover_tests(gtests)

add_executable(gmocks gmock.cpp)
target_link_libraries(gmocks PRIVATE tradefair::libcustomer GTest::gmock_main)
target_compile_options(gmocks PRIVATE ${BASE_COMPILE_FLAGS})
target_compile_features(gmocks PRIVATE cxx_std_17)
gtest_discover_tests(gmocks)

add_executable(drogontests drogontest.cpp)
target_link_libraries(drogontests PRIVATE tradefair::libcustomer)
target_compile_options(drogontests PRIVATE ${BASE_COMPILE_FLAGS})
target_compile_features(drogontests PRIVATE cxx_std_17)
add_test(NAME drogontests COMMAND drogontests)

add_executable(boostuttests boostuttest.cpp)
target_link_libraries(boostuttests PRIVATE tradefair::libcustomer Boost::ut)
target_compile_options(boostuttests PRIVATE ${BASE_COMPILE_FLAGS})
target_compile_features(boostuttests PRIVATE cxx_std_20)
set_target_properties(boostuttests PROPERTIES CXX_SCAN_FOR_MODULES on)
add_test(NAME boostuttests COMMAND boostuttests)

add_executable(cpputests cpputest.cpp)
target_link_libraries(cpputests PRIVATE tradefair::libcustomer
                                        cpputest::cpputest)
target_compile_options(cpputests PRIVATE ${BASE_COMPILE_FLAGS})
add_test(NAME cpputests COMMAND cpputests)

add_executable(doctests doctest.cpp)
target_link_libraries(doctests PRIVATE tradefair::libcustomer doctest::doctest)
target_compile_options(doctests PRIVATE ${BASE_COMPILE_FLAGS})
doctest_discover_tests(doctests)

add_library(compiletimetests OBJECT compiletime.cpp)
target_compile_features(compiletimetests PRIVATE cxx_std_17)
target_compile_options(compiletimetests PRIVATE ${BASE_COMPILE_FLAGS})
target_link_libraries(compiletimetests PRIVATE tradefair::libcustomer)
