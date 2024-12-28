#include <catch2/catch_all.hpp>

#include "customer/customer.h"

TEST_CASE("Basic responses",
          "Given Name When Prepare Responses Then Greets Friendly") {
  const auto name = U("Bob");
  auto [status, value] = responder{}.prepare_response(name);
  REQUIRE(status == web::http::status_codes::OK);
  REQUIRE(value == web::json::value(U("Hello, Bob!")));
}
