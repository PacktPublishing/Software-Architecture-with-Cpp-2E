#pragma once

#include <drogon/drogon.h>
#include <spdlog/sinks/stdout_sinks.h>
#include <spdlog/spdlog.h>

#include <string>
#include <utility>

class responder {
public:
  auto prepare_response(const std::string &name)
      -> std::pair<drogon::HttpStatusCode, Json::Value>;

  auto respond(drogon::HttpStatusCode status, const Json::Value &response,
               std::function<void(const drogon::HttpResponsePtr &)> &&callback)
      -> void;
};

template <typename Responder>
void handle_get(
    const drogon::HttpRequestPtr &request, Responder &responder,
    std::function<void(const drogon::HttpResponsePtr &)> &&callback) {
  const auto sink = std::make_shared<spdlog::sinks::stdout_sink_st>();
  const auto logger = std::make_shared<spdlog::logger>("responder", sink);

  SPDLOG_LOGGER_INFO(logger, "get optional parameter 'name'");
  auto name = request->getOptionalParameter<std::string>("name");

  if (!name) {
    const auto err = "missing value for 'name'";

    SPDLOG_LOGGER_ERROR(logger, err);
    responder.respond(drogon::k400BadRequest, Json::Value(err),
                      std::move(callback));
    return;
  }

  SPDLOG_LOGGER_INFO(logger, "return response to '{0}'", name.value());

  const auto [code, response] = responder.prepare_response(name.value());
  responder.respond(code, response, std::move(callback));
}
