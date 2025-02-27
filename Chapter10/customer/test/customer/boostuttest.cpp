#define BOOST_UT_DISABLE_MODULE
#include <boost/ut.hpp>
// import boost.ut;

#include "customer/responder.h"

namespace ut = boost::ut;

ut::suite<"responder tests"> _ = [] {
  using namespace boost::ut;
  "basic_responses"_test = [] {
    const auto name = "Bob";
    const auto [status, value] = responder{}.prepare_response(name);

    should("given_name_when_prepare_responses_then_greets_friendly") = [status,
                                                                        value] {
      expect(status == drogon::k200OK);
      expect(value == "Hello, Bob!");
    };
  };
};

int main() {}
