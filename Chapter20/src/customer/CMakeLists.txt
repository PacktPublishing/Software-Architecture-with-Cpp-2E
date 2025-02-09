add_library(libcustomer responder.cpp logger.cpp metrics.cpp tracer.cpp)
add_library(tradefair::libcustomer ALIAS libcustomer)
set_target_properties(libcustomer PROPERTIES OUTPUT_NAME customer)
target_compile_features(libcustomer PUBLIC cxx_std_17)
target_include_directories(
  libcustomer PUBLIC $<INSTALL_INTERFACE:include>
                     $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>)
target_link_libraries(
  libcustomer PUBLIC Drogon::Drogon opentelemetry-cpp::opentelemetry-cpp
                     grpc::grpc)
set_target_properties(libcustomer PROPERTIES CXX_EXTENSIONS OFF)
target_compile_options(libcustomer PRIVATE ${BASE_COMPILE_FLAGS})

add_executable(customer main.cpp)
target_compile_features(customer PRIVATE cxx_std_17)
target_link_libraries(customer PRIVATE libcustomer)
set_target_properties(customer PROPERTIES CXX_EXTENSIONS OFF)
target_compile_options(customer PRIVATE ${BASE_COMPILE_FLAGS})

# Docker support

find_program(Docker_EXECUTABLE docker)
if(NOT Docker_EXECUTABLE)
  message(WARNING "Docker not found")
endif()

configure_file(${CMAKE_SOURCE_DIR}/docker/Dockerfile
               ${PROJECT_BINARY_DIR}/Dockerfile COPYONLY)

add_custom_target(
  docker
  COMMENT "Preparing Docker image"
  COMMAND ${Docker_EXECUTABLE} build ${PROJECT_BINARY_DIR} -t
          customer:${PROJECT_VERSION} -t customer:latest --no-cache
  VERBATIM)
add_dependencies(docker libcustomer)
