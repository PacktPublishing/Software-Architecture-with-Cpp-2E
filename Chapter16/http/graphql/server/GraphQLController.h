#ifndef GRAPHQL_GRAPHQLCONTROLLER_H
#define GRAPHQL_GRAPHQLCONTROLLER_H

#include <drogon/HttpController.h>
#include <graphqlservice/GraphQLService.h>

class GraphQLController : public drogon::HttpController<GraphQLController> {
public:
  METHOD_LIST_BEGIN
  ADD_METHOD_TO(GraphQLController::handleGraphQL, "/graphql", drogon::Post);
  METHOD_LIST_END

  void handleGraphQL(
      const drogon::HttpRequestPtr &req,
      std::function<void(const drogon::HttpResponsePtr &)> &&callback);
};

#endif // GRAPHQL_GRAPHQLCONTROLLER_H
