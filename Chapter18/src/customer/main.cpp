#include <drogon/drogon.h>

#include "customer/logger.h"
#include "customer/metrics.h"
#include "customer/responder.h"
#include "customer/tracer.h"

using namespace drogon;

namespace trace_api = opentelemetry::trace;

int main() {
  otlp_logger::init_logger();
  otlp_metrics::init_metrics();
  otlp_tracer::init_tracer();

  const auto logger = otlp_logger::get_logger("main");

  auto get_responder = responder{};

  app()
      .addListener("0.0.0.0", 8080)
      .setThreadNum(8)
      .enableServerHeader(false)
      .registerHandler(
          "/customer/v1",
          [&, func = __func__](
              const HttpRequestPtr &request,
              std::function<void(const HttpResponsePtr &)> &&callback) {
            const auto tracer = otlp_tracer::get_tracer("http-server");
            auto span = otlp_tracer::get_http_request_span(
                request, tracer, "customer/handle_get/outer");
            auto scope = opentelemetry::nostd::shared_ptr<
                trace_api::Tracer>::element_type::WithActiveSpan(span);

            const auto ctx = span->GetContext();
            logger->Info(std::string(func) + ": handling HTTP request to " +
                             request->path(),
                         ctx.trace_id(), ctx.span_id(), ctx.trace_flags(),
                         std::chrono::system_clock::now());

            span->AddEvent("Processing request");
            handle_get(request, get_responder, std::move(callback));

            span->End();
          },
          {Get})
      .registerHandler(
          // combines liveness and readiness health checks due to the simplicity
          "/health",
          [&](const HttpRequestPtr &,
              std::function<void(const HttpResponsePtr &)> &&callback) {
            const auto resp =
                HttpResponse::newHttpResponse(k200OK, CT_TEXT_PLAIN);
            resp->setBody("OK");
            callback(resp);
          },
          {Get})
      .run();

  return EXIT_SUCCESS;
}
