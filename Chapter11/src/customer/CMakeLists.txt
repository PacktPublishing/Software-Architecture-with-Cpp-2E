add_library(libcustomer responder.cpp)
add_library(tradefair::libcustomer ALIAS libcustomer)
set_target_properties(libcustomer PROPERTIES OUTPUT_NAME customer)
target_compile_features(libcustomer PUBLIC cxx_std_20)
target_include_directories(
  libcustomer PUBLIC $<INSTALL_INTERFACE:include>
                     $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>)
target_link_libraries(libcustomer PUBLIC Drogon::Drogon spdlog::spdlog)
set_target_properties(libcustomer PROPERTIES CXX_EXTENSIONS OFF)
target_compile_options(libcustomer PRIVATE ${BASE_COMPILE_FLAGS})

add_executable(customer main.cpp promstat.cpp)
target_compile_features(customer PRIVATE cxx_std_20)
target_link_libraries(customer PRIVATE libcustomer)
set_target_properties(customer PROPERTIES CXX_EXTENSIONS OFF)
target_compile_options(customer PRIVATE ${BASE_COMPILE_FLAGS})

add_custom_command(
  TARGET customer
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/config.json
          ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/config.json
  VERBATIM)
