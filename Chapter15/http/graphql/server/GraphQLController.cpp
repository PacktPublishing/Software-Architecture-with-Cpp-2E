#include "GraphQLController.h"

#include <graphqlservice/JSONResponse.h>

#include "QueryObject.h"
#include "ServiceSchema.h"

class YourQueryPImpl {
public:
  static std::string getName() { return "Hello from GraphQL"; }
};

void GraphQLController::handleGraphQL(
    const drogon::HttpRequestPtr &req,
    std::function<void(const drogon::HttpResponsePtr &)> &&callback) {
  auto jsonBody = req->getJsonObject();
  if (!jsonBody) {
    auto resp =
        drogon::HttpResponse::newHttpJsonResponse(Json::Value("Invalid JSON"));
    resp->setStatusCode(drogon::k400BadRequest);
    callback(resp);
    return;
  }

  std::string query = (*jsonBody)["query"].asString();
  std::string operationName = jsonBody->get("operationName", "").asString();

  auto queryImpl = std::make_shared<YourQueryPImpl>();
  graphql::greet::Operations operations(queryImpl);

  auto ast = graphql::peg::parseString(query);

  graphql::service::RequestResolveParams params{ast};
  params.operationName = operationName;

  auto result = operations.resolve(std::move(params)).get();

  std::string jsonString = graphql::response::toJSON(std::move(result));

  Json::Value jsonResult;
  Json::CharReaderBuilder builder;
  std::istringstream iss(jsonString);
  Json::String errs;
  Json::parseFromStream(builder, iss, &jsonResult, &errs);

  auto resp = drogon::HttpResponse::newHttpJsonResponse(jsonResult);
  callback(resp);
}
