#include <gtest/gtest.h>

#include "customer/responder.h"

TEST(basic_responses, given_name_when_prepare_responses_then_greets_friendly) {
  const auto name = "Bob";
  const auto [status, value] = responder::prepare_response(name);
  ASSERT_EQ(status, drogon::k200OK);
  ASSERT_EQ(value, "Hello, Bob!");
}
