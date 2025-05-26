cmake_minimum_required(VERSION 4.0.0)

set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "a9e1cf81-9932-4810-974b-6eccaf14e457")
set(CMAKE_CXX_MODULE_STD 1)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(
  Stores
  VERSION 0.0.4
  LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_BINARY_DIR}")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

include(CommonCompileFlags)

add_library(libstores)
add_library(stores::libstores ALIAS libstores)
set_target_properties(libstores PROPERTIES OUTPUT_NAME stores)
target_compile_options(libstores PRIVATE ${BASE_COMPILE_FLAGS})

target_sources(
  libstores
  PUBLIC FILE_SET
         CXX_MODULES
         BASE_DIRS
         src/stores
         FILES
         src/stores/customer.cppm
         src/stores/merchant.cppm
         src/stores/store.cppm
         src/stores/store_item.cppm)

target_sources(libstores PUBLIC FILE_SET HEADERS BASE_DIRS include FILES
                                include/stores/placeholder.h)

add_executable(stores src/main.cpp)
target_link_libraries(stores PRIVATE libstores)
target_compile_options(stores PRIVATE ${BASE_COMPILE_FLAGS})

include(CMakePackageConfigHelpers)
configure_file(${PROJECT_SOURCE_DIR}/cmake/StoresConfig.cmake.in
               StoresConfig.cmake @ONLY)

write_basic_package_version_file(
  StoresConfigVersion.cmake
  VERSION ${PACKAGE_VERSION}
  COMPATIBILITY AnyNewerVersion)

include(GNUInstallDirs) # set CMAKE_INSTALL_PREFIX to change the destination

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/StoresConfig.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/StoresConfigVersion.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Stores)

install(
  TARGETS libstores stores
  EXPORT StoresTargets
  FILE_SET HEADERS
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
  FILE_SET CXX_MODULES
  DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

install(
  EXPORT StoresTargets
  FILE StoresTargets.cmake
  NAMESPACE stores::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Stores)
