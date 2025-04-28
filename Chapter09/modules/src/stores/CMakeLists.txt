add_library(libstores)
add_library(stores::libstores ALIAS libstores)
set_target_properties(libstores PROPERTIES OUTPUT_NAME stores)
target_sources(
  libstores
  PUBLIC FILE_SET
         CXX_MODULES
         FILES
         customer.cppm
         merchant.cppm
         store.cppm
         store_item.cppm)

target_compile_features(libstores PUBLIC cxx_std_20)
target_include_directories(
  libstores PUBLIC $<INSTALL_INTERFACE:include>
                   $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>)
set_target_properties(libstores PROPERTIES CXX_EXTENSIONS OFF)
target_compile_options(libstores PRIVATE ${BASE_COMPILE_FLAGS})

add_executable(stores main.cpp)
target_compile_features(stores PRIVATE cxx_std_20)
target_link_libraries(stores PRIVATE libstores)
set_target_properties(stores PROPERTIES CXX_EXTENSIONS OFF)
target_compile_options(stores PRIVATE ${BASE_COMPILE_FLAGS})

# Installing

include(GNUInstallDirs) # set CMAKE_INSTALL_PREFIX to change the destination

install(
  TARGETS libstores stores
  EXPORT StoresTargets
  FILE_SET CXX_MODULES
  DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

# the last slash is important here
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/ DESTINATION include)

install(
  EXPORT StoresTargets
  FILE StoresTargets.cmake
  NAMESPACE stores::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Stores
  CXX_MODULES_DIRECTORY cxx-modules)

configure_file(${PROJECT_SOURCE_DIR}/cmake/StoresConfig.cmake.in
               StoresConfig.cmake @ONLY)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
  StoresConfigVersion.cmake
  VERSION ${PACKAGE_VERSION}
  COMPATIBILITY AnyNewerVersion)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/StoresConfig.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/StoresConfigVersion.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Stores)

install(FILES ${PROJECT_SOURCE_DIR}/LICENSE DESTINATION ${CMAKE_INSTALL_DOCDIR})

# Exporting

export(
  TARGETS libstores stores
  NAMESPACE stores::
  FILE StoresTargets.cmake CXX_MODULES_DIRECTORY cxx-modules)

set(CMAKE_EXPORT_PACKAGE_REGISTRY ON)
export(PACKAGE stores)
