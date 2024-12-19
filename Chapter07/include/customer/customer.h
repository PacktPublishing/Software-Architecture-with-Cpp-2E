#pragma once

#include <cpprest/http_msg.h>
#include <cpprest/json.h>

#include <string>
#include <utility>

using ::utility::string_t;

class responder {
 public:
  auto prepare_response(const string_t &name)
      -> std::pair<::web::http::status_code, ::web::json::value>;

  auto respond(const ::web::http::http_request &request,
               ::web::http::status_code status,
               const ::web::json::value &response) -> void;
};

template <typename Responder>
void handle_get(const ::web::http::http_request &req, Responder &responder) {
  using namespace ::web;
  using namespace ::web::http;
  using namespace ::utility;

  auto parameters = uri::split_query(req.request_uri().query());
  auto key_value_it = parameters.find(U("name"));

  if (key_value_it == end(parameters)) {
    auto err = U("Missing value for 'name'");
    responder.respond(req, status_codes::BadRequest, json::value::string(err));
    return;
  }

  const auto &name = key_value_it->second;
  const auto [code, response] = responder.prepare_response(name);
  responder.respond(req, code, response);
}
