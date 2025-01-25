#include "customer/view_controller.h"

void ViewController::asyncHandleHttpRequest(
    const HttpRequestPtr &request,
    std::function<void(const HttpResponsePtr &)> &&callback) {
  auto name = request->getOptionalParameter<std::string>("name");
  HttpViewData data;
  if (name) {
    data["name"] = name.value();
  }
  const auto viewResponse = HttpResponse::newHttpViewResponse("view", data);
  callback(viewResponse);
}
