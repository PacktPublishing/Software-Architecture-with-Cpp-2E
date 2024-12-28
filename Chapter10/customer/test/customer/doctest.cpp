#include "customer/customer.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_CASE("Basic responses") {
  auto name = U("Bob");
  auto [status, value] = responder{}.prepare_response(name);
  REQUIRE(status == web::http::status_codes::OK);
  REQUIRE(value == web::json::value(U("Hello, Bob!")));
}
