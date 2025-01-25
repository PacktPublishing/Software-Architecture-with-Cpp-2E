#include <drogon/drogon.h>

#include "customer/controller.h"
#include "customer/responder.h"
#include "customer/view_controller.h"

using namespace drogon;

int main() {
  auto get_responder = responder{};

  app()
      .addListener("127.0.0.1", 8080)
      .setThreadNum(8)
      .enableServerHeader(false)
      .registerHandler(
          "/customer/v1",
          [&](const HttpRequestPtr &request,
              std::function<void(const HttpResponsePtr &)> &&callback) {
            handle_get(request, get_responder, std::move(callback));
          },
          {Get})
      .registerController(std::make_shared<Controller>())
      .registerController(std::make_shared<ViewController>())
      .run();

  return EXIT_SUCCESS;
}
