// TODO: fix transitive dependencies in
// https://conan.io/center/recipes/drogon?version=1.9.8 when with_boost=False
#define BOOST_TEST_UNIT_TEST_SUITE_IPP_012205GER
#define BOOST_TEST_UNIT_TEST_PARAMETERS_IPP_012205GER

#define BOOST_TEST_MODULE basic_responses
#include <boost/test/included/unit_test.hpp>

#include "customer/responder.h"

BOOST_AUTO_TEST_CASE(given_name_when_prepare_responses_then_greets_friendly) {
  const auto name = "Bob";
  const auto [status, value] = responder{}.prepare_response(name);
  BOOST_CHECK_EQUAL(status, drogon::k200OK);
  BOOST_CHECK_EQUAL(value, "Hello, Bob!");
}
