#include <cpprest/details/basic_types.h>

#include "customer/customer.h"

using namespace ::web;
using namespace ::web::http;
using ::utility::string_t;

auto responder::respond(const http_request &request, status_code status,
                        const json::value &response) -> void {
  json::value resp;
  resp[U("status")] = json::value::number(status);
  resp[U("response")] = response;
  request.reply(status, resp);
}

auto responder::prepare_response(const string_t &name)
    -> std::pair<status_code, json::value> {
  return {status_codes::OK, json::value::string(U("Hello, ") + name + U("!"))};
}
