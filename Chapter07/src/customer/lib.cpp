#include <drogon/drogon.h>

#include "customer/customer.h"

using namespace drogon;

auto responder::prepare_response(const std::string &name)
    -> std::pair<drogon::HttpStatusCode, Json::Value> {
  return {k200OK, "Hello, " + name + "!"};
}

auto responder::respond(const HttpStatusCode status,
                        const Json::Value &response,
                        std::function<void(const HttpResponsePtr &)> &&callback)
    -> void {
  Json::Value jsonBody;
  jsonBody["status"] = status;
  jsonBody["response"] = response;

  const auto jsonResponse =
      HttpResponse::newHttpJsonResponse(std::move(jsonBody));
  callback(jsonResponse);
}
