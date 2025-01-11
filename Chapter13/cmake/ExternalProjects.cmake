include(FetchContent)

FetchContent_Declare(
  SaferCPlusPlus
  GIT_REPOSITORY "https://github.com/duneroadrunner/SaferCPlusPlus.git"
  GIT_TAG "master"
  GIT_SHALLOW ON)

FetchContent_MakeAvailable(SaferCPlusPlus)

add_library(SaferCppExt::SaferCppExt INTERFACE IMPORTED GLOBAL)
target_include_directories(SaferCppExt::SaferCppExt SYSTEM
                           INTERFACE "${safercplusplus_SOURCE_DIR}/include")
add_dependencies(SaferCppExt::SaferCppExt SaferCPlusPlus)
