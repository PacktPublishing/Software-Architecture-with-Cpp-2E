#include "inja_controller.h"

#include <inja/inja.hpp>

#include "customer/responder.h"

namespace {
const std::string html_template = R"(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>{{ default(name, "anonymous") }}</title>
</head>
<body>
  Hello, {{ default(name, "anonymous") }}!
  {% if not exists("name") %}
  <br>You can revisit the this page, but append ?name=<i>your_name</i> to change the name
  {% endif %}
</body>
</html>)";
}

void InjaController::asyncHandleHttpRequest(
    const HttpRequestPtr &request,
    std::function<void(const HttpResponsePtr &)> &&callback) {
  auto name = request->getOptionalParameter<std::string>("name");
  inja::json data;
  if (name) {
    data["name"] = html_escape(name.value());
  }

  const std::string html_doc = inja::render(html_template, data);

  const auto httpResponse = HttpResponse::newHttpResponse();
  httpResponse->setBody(html_doc);
  callback(httpResponse);
}
