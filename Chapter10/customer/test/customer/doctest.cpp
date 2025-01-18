#include <tuple>

#include "customer/responder.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_CASE("Basic responses") {
  auto name = "Bob";
  drogon::HttpStatusCode status;
  Json::Value value;
  std::tie(status, value) = responder{}.prepare_response(name);
  REQUIRE(status == drogon::k200OK);
  REQUIRE(value == "Hello, Bob!");
}
