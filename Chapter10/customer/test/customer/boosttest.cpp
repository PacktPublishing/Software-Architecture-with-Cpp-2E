// TODO: fix transitive dependencies in
// https://conan.io/center/recipes/drogon when with_boost=False
#define BOOST_TEST_UNIT_TEST_SUITE_IPP_012205GER
#define BOOST_TEST_UNIT_TEST_PARAMETERS_IPP_012205GER
#define BOOST_TEST_COMPILER_LOG_FORMATTER_IPP_020105GER
#define BOOST_TEST_JUNIT_LOG_FORMATTER_IPP__
#define BOOST_TEST_TEST_TOOLS_IPP_012205GER
#define BOOST_TEST_TREE_DECORATOR_IPP_091911GER
#define BOOST_TEST_DEBUG_API_IPP_112006GER

#define BOOST_TEST_MODULE basic_responses
#include <boost/test/included/unit_test.hpp>

#include "customer/responder.h"

BOOST_AUTO_TEST_CASE(given_name_when_prepare_responses_then_greets_friendly) {
  const auto name = "Bulk Bogan";
  const auto [status, value] = responder{}.prepare_response(name);
  BOOST_CHECK_EQUAL(status, drogon::k200OK);
  BOOST_CHECK_EQUAL(value, "Hello, Bulk Bogan!");
}
