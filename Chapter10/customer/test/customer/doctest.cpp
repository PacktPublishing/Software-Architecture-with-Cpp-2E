#include <tuple>

#include "customer/customer.h"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

using namespace ::web;
using namespace ::web::http;

TEST_CASE("Basic responses") {
  auto name = U("Bob");
  status_code status;
  json::value value;
  std::tie(status, value) = responder{}.prepare_response(name);
  REQUIRE(status == web::http::status_codes::OK);
  REQUIRE(value == web::json::value(U("Hello, Bob!")));
}
