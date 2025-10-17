set(GRAPHQL_SCHEMA ${PROJECT_SOURCE_DIR}/schema.graphql)

set(GENERATED_DIR ${CMAKE_CURRENT_BINARY_DIR}/generated)
set(GENERATED_GRAPHQL_FILES
    ${GENERATED_DIR}/ServiceSchema.cpp ${GENERATED_DIR}/ServiceSchema.h
    ${GENERATED_DIR}/QueryObject.cpp ${GENERATED_DIR}/QueryObject.h)

add_custom_command(
  OUTPUT ${GENERATED_GRAPHQL_FILES}
  COMMAND
    $<TARGET_FILE:cppgraphqlgen::schemagen> --schema ${GRAPHQL_SCHEMA} --prefix
    Service --namespace greet --source-dir ${GENERATED_DIR} --header-dir
    ${GENERATED_DIR}
  DEPENDS ${GRAPHQL_SCHEMA}
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
  COMMENT "Generating C++ types from ${GRAPHQL_SCHEMA}"
  VERBATIM)
add_custom_target(schema-gen DEPENDS ${GENERATED_GRAPHQL_FILES})

add_executable(server main.cpp GraphQLController.cpp GraphQLController.h
                      ${GENERATED_GRAPHQL_FILES})
target_include_directories(server PUBLIC ${GENERATED_DIR})
target_link_libraries(
  server PRIVATE Drogon::Drogon cppgraphqlgen::graphqlservice
                 cppgraphqlgen::graphqljson)

add_dependencies(server schema-gen)
