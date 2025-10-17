#include <iostream>

#include <drogon/HttpClient.h>
#include <drogon/drogon.h>
#include <graphqlservice/JSONResponse.h>

#include "ServiceClient.h"

using namespace drogon;

using namespace graphql::client::query::GetName;

int main() {
  auto client = HttpClient::newHttpClient("http://localhost:8080");

  Json::Value requestBody;
  requestBody["query"] = GetRequestText();
  requestBody["operationName"] = GetOperationName();

  auto req = HttpRequest::newHttpJsonRequest(requestBody);
  req->setMethod(Post);
  req->setPath("/graphql");
  req->addHeader("Content-Type", "application/json");

  client->sendRequest(req, [](ReqResult result, const HttpResponsePtr &resp) {
    if (result == ReqResult::Ok && resp) {
      auto jsonResponse = resp->getJsonObject();

      graphql::response::Value gqlResponse(graphql::response::Type::Map);
      auto data = (*jsonResponse)["data"];

      auto parsedResponse = graphql::response::parseJSON(data.toStyledString());
      auto response = parseResponse(std::move(parsedResponse));

      std::cout << "Name: " << response.name << std::endl;
    } else {
      std::cerr << "Request failed" << std::endl;
    }

    app().quit();
  });

  app().run();

  return 0;
}
