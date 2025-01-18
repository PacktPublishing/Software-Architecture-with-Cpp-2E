#include "customer/responder.h"

/* clang-format off */
#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestHarness.h>
/* clang-format on */

TEST_GROUP(basic_responses){};

TEST(basic_responses, given_name_when_prepare_responses_then_greets_friendly) {
  const auto name = "Bob";
  const auto [status, value] = responder{}.prepare_response(name);
  CHECK_EQUAL(status, drogon::k200OK);
  CHECK(value == "Hello, Bob!");
}

int main(const int ac, char **av) {
  return CommandLineTestRunner::RunAllTests(ac, av);
}
