add_library(libcustomer responder.cpp controller.cpp)
add_library(tradefair::libcustomer ALIAS libcustomer)
set_target_properties(libcustomer PROPERTIES OUTPUT_NAME customer)
target_compile_features(libcustomer PUBLIC cxx_std_17)
target_include_directories(
  libcustomer PUBLIC $<INSTALL_INTERFACE:include>
                     $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>)
target_link_libraries(libcustomer PUBLIC Drogon::Drogon)
set_target_properties(libcustomer PROPERTIES CXX_EXTENSIONS OFF)
target_compile_options(libcustomer PRIVATE ${BASE_COMPILE_FLAGS})

add_executable(customer main.cpp)
target_compile_features(customer PRIVATE cxx_std_17)
target_link_libraries(customer PRIVATE libcustomer)
set_target_properties(customer PROPERTIES CXX_EXTENSIONS OFF)
target_compile_options(customer PRIVATE ${BASE_COMPILE_FLAGS})

# Installing

include(GNUInstallDirs) # set CMAKE_INSTALL_PREFIX to change the destination

install(
  TARGETS libcustomer customer
  EXPORT CustomerTargets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

# the last slash is important here
install(DIRECTORY ../../include/ DESTINATION include)

install(
  EXPORT CustomerTargets
  FILE CustomerTargets.cmake
  NAMESPACE tradefair::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Customer)

configure_file(../../cmake/CustomerConfig.cmake.in CustomerConfig.cmake @ONLY)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
  CustomerConfigVersion.cmake
  VERSION ${PACKAGE_VERSION}
  COMPATIBILITY AnyNewerVersion)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/CustomerConfig.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/CustomerConfigVersion.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Customer)

install(FILES ../../LICENSE DESTINATION ${CMAKE_INSTALL_DOCDIR})

# Exporting

export(
  TARGETS libcustomer customer
  NAMESPACE tradefair::
  FILE CustomerTargets.cmake)

set(CMAKE_EXPORT_PACKAGE_REGISTRY ON)
export(PACKAGE tradefair)

# Packaging support

set(CPACK_PACKAGE_VENDOR "Authors")
set(CPACK_PACKAGE_CONTACT "author@example.com")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY
    "Library and app for the Customer microservice")
set(CPACK_PACKAGE_DIRECTORY packages)
set(CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${PROJECT_VERSION_PATCH})
# used by installers like NSIS, IFW and INNOSETUP
set(CPACK_RESOURCE_FILE_LICENSE "${PROJECT_SOURCE_DIR}/LICENSE")
set(CPACK_RESOURCE_FILE_README "${PROJECT_SOURCE_DIR}/README.md")

list(APPEND CPACK_GENERATOR TGZ ZIP)
if(LINUX)
  find_program(DPKG_PROGRAM dpkg)
  if(DPKG_PROGRAM)
    list(APPEND CPACK_GENERATOR DEB)
    set(CPACK_DEBIAN_PACKAGE_DEPENDS
        "${CPACK_DEBIAN_PACKAGE_DEPENDS} libdrogon1t64 (>= 1.8.7)")
    set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)
  else()
    message(STATUS "dpkg not found - won't be able to create DEB packages")
  endif()

  find_program(RPMBUILD_PROGRAM rpmbuild)
  if(RPMBUILD_PROGRAM)
    list(APPEND CPACK_GENERATOR RPM)
    # set(CPACK_RPM_PACKAGE_REQUIRES "${CPACK_RPM_PACKAGE_REQUIRES}")
  else()
    message(STATUS "rpmbuild not found - won't be able to create RPM packages")
  endif()
endif()

# linuxdeploy detects an executable file in this directory
set(CPACK_PACKAGING_INSTALL_PREFIX "/usr")

find_program(LINUXDEPLOY_PROGRAM NAMES linuxdeploy linuxdeploy-x86_64.AppImage
                                       linuxdeploy-aarch64.AppImage)
if(LINUXDEPLOY_PROGRAM)
  list(APPEND CPACK_GENERATOR External)
  configure_file(../../cmake/CPackExternal.cmake.in
                 "${CMAKE_BINARY_DIR}/CPackExternal.cmake" COPYONLY)
  set(CPACK_EXTERNAL_PACKAGE_SCRIPT "${CMAKE_BINARY_DIR}/CPackExternal.cmake")
  set(CPACK_EXTERNAL_ENABLE_STAGING YES)
  configure_file(../../resources/customer.desktop
                 "${CMAKE_BINARY_DIR}/customer.desktop" COPYONLY)
  configure_file(../../resources/customer.svg
                 "${CMAKE_BINARY_DIR}/customer.svg" COPYONLY)
else()
  message(
    STATUS
      "linuxdeploy not found - won't be able to create AppImage executables")
endif()

set(CPACK_SOURCE_IGNORE_FILES /.git /dist /.*build.* /\\\\.DS_Store)

include(CPack)
