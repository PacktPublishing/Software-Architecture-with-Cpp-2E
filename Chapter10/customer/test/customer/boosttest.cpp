#define BOOST_TEST_MODULE basic_responses
#include <boost/test/included/unit_test.hpp>

#include "customer/customer.h"

BOOST_AUTO_TEST_CASE(given_name_when_prepare_responses_then_greets_friendly) {
  const auto name = U("Bob");
  auto [status, value] = responder{}.prepare_response(name);
  BOOST_CHECK_EQUAL(status, web::http::status_codes::OK);
  BOOST_CHECK_EQUAL(value, web::json::value(U("Hello, Bob!")));
}
