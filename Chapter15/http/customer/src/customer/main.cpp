#include <drogon/drogon.h>

#include "customer/responder.h"

using namespace drogon;

int main() {
  auto get_responder = responder{};

  app()
      .addListener("0.0.0.0", 8080)
      .setThreadNum(0)
      .enableServerHeader(false)
      .setDocumentRoot("./static")
      .setFileTypes(
          {"html", "js", "css", "gif", "png", "jpg", "ico", "yaml", "json"})
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
