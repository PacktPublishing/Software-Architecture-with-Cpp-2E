add_executable(merchanttests_gmock reviewtests_gmock.cpp)
target_link_libraries(merchanttests_gmock PRIVATE merchants GTest::gmock
                                                  GTest::gmock_main)
gtest_discover_tests(merchanttests_gmock)

add_executable(merchanttests_trompeloeil reviewtests_trompeloeil.cpp)
target_compile_features(merchanttests_trompeloeil PRIVATE cxx_std_17)
target_link_libraries(
  merchanttests_trompeloeil PRIVATE merchants trompeloeil::trompeloeil
                                    Catch2::Catch2WithMain)
catch_discover_tests(merchanttests_trompeloeil)

add_executable(merchanttests_cpputest reviewtests_cpputest.cpp)
target_link_libraries(merchanttests_cpputest PRIVATE merchants
                                                     cpputest::cpputest)
target_compile_options(merchanttests_cpputest PRIVATE ${BASE_COMPILE_FLAGS})
add_test(NAME merchanttests_cpputest COMMAND merchanttests_cpputest)
