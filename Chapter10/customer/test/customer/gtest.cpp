#include <gtest/gtest.h>

#include "customer/customer.h"

TEST(basic_responses, given_name_when_prepare_responses_then_greets_friendly) {
  const auto name = U("Bob");
  auto [status, value] = responder{}.prepare_response(name);
  ASSERT_EQ(status, web::http::status_codes::OK);
  ASSERT_EQ(value, web::json::value(U("Hello, Bob!")));
}
