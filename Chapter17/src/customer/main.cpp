#include <drogon/drogon.h>
#include <spdlog/sinks/stdout_sinks.h>
#include <spdlog/spdlog.h>

#include "customer/promstat.h"
#include "customer/responder.h"

using namespace drogon;

int main() {
  auto get_responder = responder{};

  const auto logger = spdlog::stdout_logger_mt("main");

  app()
      .loadConfigFile("config.json")
      .registerMiddleware(std::make_shared<PromStat>())
      .registerHandler(
          "/customer/v1",
          [&logger, &get_responder](
              const HttpRequestPtr &request,
              std::function<void(const HttpResponsePtr &)> &&callback) {
            SPDLOG_LOGGER_INFO(logger, "handling HTTP request to {}",
                               request->path());

            handle_get(request, get_responder, std::move(callback));
          },
          {Get, "PromStat"})
      .registerHandler(
          // combines liveness and readiness health checks due to the simplicity
          "/health",
          [](const HttpRequestPtr &,
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
