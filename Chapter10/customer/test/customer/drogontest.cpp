#define DROGON_TEST_MAIN
#include <drogon/drogon_test.h>

#include "customer/responder.h"

DROGON_TEST(given_name_when_prepare_responses_then_greets_friendly) {
  const auto name = "Bob";
  const auto [status, value] = responder{}.prepare_response(name);
  CHECK(status == drogon::k200OK);
  CHECK(value == "Hello, Bob!");
}

int main(const int argc, char** argv) { return drogon::test::run(argc, argv); }
