cmake_minimum_required(VERSION 3.16)

project(
  gRPC
  VERSION 0.0.1
  LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

find_program(CCACHE_PROGRAM ccache)
if(CCACHE_PROGRAM)
  set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CCACHE_PROGRAM}")
endif()

if(NOT MSVC)
  find_package(gRPC REQUIRED)
  find_package(protobuf REQUIRED)

  add_library(grpc_service service.proto)
  target_link_libraries(grpc_service PUBLIC protobuf::libprotobuf gRPC::grpc++)
  target_compile_features(grpc_service PUBLIC cxx_std_20)

  include(protobuf-generate)
  protobuf_generate(TARGET grpc_service LANGUAGE cpp)
  protobuf_generate(
    TARGET
    grpc_service
    LANGUAGE
    grpc
    GENERATE_EXTENSIONS
    .grpc.pb.h
    .grpc.pb.cc
    PLUGIN
    "protoc-gen-grpc=\$<TARGET_FILE:gRPC::grpc_cpp_plugin>")
  target_include_directories(grpc_service PUBLIC "${CMAKE_CURRENT_BINARY_DIR}")

  add_executable(grpc_client async_client.cpp)
  target_link_libraries(grpc_client grpc_service)

  add_executable(grpc_server async_server.cpp)
  target_link_libraries(grpc_server grpc_service)
endif()
