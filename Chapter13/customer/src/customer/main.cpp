#include <drogon/drogon.h>

#include "customer/responder.h"

using namespace drogon;

int main() {
  auto get_responder = responder{};

  app()
      .addListener("0.0.0.0", 8080)
      .setThreadNum(8)
      .enableServerHeader(false)
      .registerHandler(
          "/customer/v1",
          [&](const HttpRequestPtr &request,
              std::function<void(const HttpResponsePtr &)> &&callback) {
            handle_get(request, get_responder, std::move(callback));
          },
          {Get})
      .run();

  return EXIT_SUCCESS;
}
