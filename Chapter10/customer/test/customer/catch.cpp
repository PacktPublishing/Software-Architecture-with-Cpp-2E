#include <catch2/catch_all.hpp>

#include "customer/responder.h"

TEST_CASE("Basic responses",
          "Given Name When Prepare Responses Then Greets Friendly") {
  const auto name = "Bob";
  const auto [status, value] = responder{}.prepare_response(name);
  REQUIRE(status == drogon::k200OK);
  REQUIRE(value == "Hello, Bob!");
}

int main(const int argc, char* argv[]) {
  return Catch::Session().run(argc, argv);
}
