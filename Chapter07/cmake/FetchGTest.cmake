# https://github.com/cpm-cmake/CPM.cmake?tab=readme-ov-file#options
option(
  USE_CPM_CMAKE
  "Use CPM.cmake: a small CMake script for setup-free, cross-platform, reproducible dependency management"
  ON)

if(NOT USE_CPM_CMAKE)
  include(FetchContent)

  FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.17.0
    EXCLUDE_FROM_ALL)

  # For Windows: Prevent overriding the parent project's compiler/linker
  # settings
  set(gtest_force_shared_crt
      ON
      CACHE BOOL "" FORCE)
  FetchContent_MakeAvailable(googletest)

  message(STATUS "GTest binaries are present at ${googletest_BINARY_DIR}")
else()
  include(CPM)

  # cmake-format: off
  CPMAddPackage(
    NAME googletest
    GITHUB_REPOSITORY google/googletest
    GIT_TAG v1.17.0
    VERSION 1.17.0
    EXCLUDE_FROM_ALL
    OPTIONS "BUILD_GMOCK OFF" "INSTALL_GTEST OFF" "gtest_force_shared_crt")
  # cmake-format: on
endif()
