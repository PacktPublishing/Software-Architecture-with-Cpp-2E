#include "customer/responder.h"

#include <drogon/drogon.h>

#include <sstream>

using namespace drogon;

auto responder::prepare_response(const std::string &name)
    -> std::pair<HttpStatusCode, Json::Value> {
  return {k200OK, "Hello, " + name + "!"};
}

auto responder::respond(const HttpStatusCode status,
                        const Json::Value &response,
                        std::function<void(const HttpResponsePtr &)> &&callback)
    -> void {
  Json::Value jsonBody;
  jsonBody["status"] = status;
  jsonBody["response"] = response;

  const auto jsonResponse =
      HttpResponse::newHttpJsonResponse(std::move(jsonBody));
  callback(jsonResponse);
}

std::string html_escape(const std::string &str) {
  std::ostringstream ss(str);
  for (const char ch : str) {
    switch (ch) {
      case '<':
        ss << "&lt;";
        break;
      case '>':
        ss << "&gt;";
        break;
      case ' ':
        ss << "&nbsp;";
        break;
      case '&':
        ss << "&amp;";
        break;
      case '\"':
        ss << "&quot;";
        break;
      case '\'':
        ss << "&apos;";
        break;
      default:
        ss << ch;
        break;
    }
  }

  return ss.str();
}
