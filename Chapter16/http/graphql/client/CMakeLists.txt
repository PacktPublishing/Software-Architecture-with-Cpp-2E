set(GRAPHQL_SCHEMA ${PROJECT_SOURCE_DIR}/schema.graphql)
set(GRAPHQL_QUERY ${PROJECT_SOURCE_DIR}/query.graphql)

set(GENERATED_DIR ${CMAKE_CURRENT_BINARY_DIR}/generated)
set(GENERATED_GRAPHQL_FILES ${GENERATED_DIR}/ServiceClient.cpp
                            ${GENERATED_DIR}/ServiceClient.h)

add_custom_command(
  OUTPUT ${GENERATED_GRAPHQL_FILES}
  COMMAND
    $<TARGET_FILE:cppgraphqlgen::clientgen> --schema ${GRAPHQL_SCHEMA} --request
    ${GRAPHQL_QUERY} --prefix Service --namespace greet --source-dir
    ${GENERATED_DIR} --header-dir ${GENERATED_DIR}
  DEPENDS ${GRAPHQL_SCHEMA} ${GRAPHQL_QUERY}
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
  COMMENT "Generating C++ types from ${GRAPHQL_SCHEMA} and ${GRAPHQL_QUERY}"
  VERBATIM)
add_custom_target(client-gen DEPENDS ${GENERATED_GRAPHQL_FILES})

add_executable(client main.cpp ${GENERATED_GRAPHQL_FILES})
target_include_directories(client PUBLIC ${GENERATED_DIR})
target_link_libraries(
  client PRIVATE Drogon::Drogon cppgraphqlgen::graphqlclient
                 cppgraphqlgen::graphqljson)

add_dependencies(client client-gen)
