#include "view_controller.h"

#include "customer/responder.h"

void ViewController::asyncHandleHttpRequest(
    const HttpRequestPtr &request,
    std::function<void(const HttpResponsePtr &)> &&callback) {
  auto name = request->getOptionalParameter<std::string>("name");
  HttpViewData data;
  if (name) {
    data["name"] = html_escape(name.value());
  }
  const auto viewResponse = HttpResponse::newHttpViewResponse("view", data);
  callback(viewResponse);
}
