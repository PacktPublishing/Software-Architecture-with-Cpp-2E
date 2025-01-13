#pragma once

#include <drogon/drogon.h>

#include <string>
#include <utility>

class responder {
 public:
  static auto prepare_response(const std::string &name)
      -> std::pair<drogon::HttpStatusCode, Json::Value>;

  static auto respond(
      drogon::HttpStatusCode status, const Json::Value &response,
      std::function<void(const drogon::HttpResponsePtr &)> &&callback) -> void;
};

template <typename Responder>
void handle_get(
    const drogon::HttpRequestPtr &request, Responder &responder,
    std::function<void(const drogon::HttpResponsePtr &)> &&callback) {
  auto name = request->getOptionalParameter<std::string>("name");

  if (!name) {
    const auto err = "Missing value for 'name'";
    responder.respond(drogon::k400BadRequest, Json::Value(err),
                      std::move(callback));
    return;
  }

  const auto [code, response] = responder.prepare_response(name.value());
  responder.respond(code, response, std::move(callback));
}
