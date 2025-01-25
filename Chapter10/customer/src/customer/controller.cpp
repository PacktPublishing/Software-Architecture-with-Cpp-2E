#include "customer/controller.h"

void Controller::respond(
    const HttpRequestPtr &request,
    std::function<void(const HttpResponsePtr &)> &&callback) {
  handle_get(request, get_responder, std::move(callback));
}
