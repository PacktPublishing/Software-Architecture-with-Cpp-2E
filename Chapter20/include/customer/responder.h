#pragma once

#include <drogon/drogon.h>

#include <map>
#include <string>
#include <utility>

#include "logger.h"
#include "metrics.h"
#include "tracer.h"

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
  auto span = otlp_tracer::get_tracer("http-server")
                  ->StartSpan("customer/handle_get/inner");
  auto scope = opentelemetry::nostd::shared_ptr<
      opentelemetry::trace::Tracer>::element_type::WithActiveSpan(span);
  span->AddEvent("get optional parameter 'name'");

  const auto ctx = span->GetContext();
  const auto logger = otlp_logger::get_logger("responder");

  logger->Info(std::string(__func__) + ": get optional parameter 'name'",
               ctx.trace_id(), ctx.span_id(), ctx.trace_flags(),
               std::chrono::system_clock::now());
  auto name = request->getOptionalParameter<std::string>("name");

  if (!name) {
    const auto err = "missing value for 'name'";
    span->AddEvent(err);
    logger->Error(std::string(__func__) + ": " + err, ctx.trace_id(),
                  ctx.span_id(), ctx.trace_flags(),
                  std::chrono::system_clock::now());

    responder.respond(drogon::k400BadRequest, Json::Value(err),
                      std::move(callback));
    return;
  }

  const auto counter = otlp_metrics::init_int64_counter("handle_get");

  const std::map<std::string, std::string> labels = {{"name", name.value()}};
  const auto attributes = opentelemetry::common::KeyValueIterableView{labels};
  counter->Add(1, attributes);

  span->AddEvent("return response");
  logger->Info(
      std::string(__func__) + ": return response to '" + name.value() + "'",
      ctx.trace_id(), ctx.span_id(), ctx.trace_flags(),
      std::chrono::system_clock::now());

  const auto [code, response] = responder.prepare_response(name.value());
  responder.respond(code, response, std::move(callback));
}
