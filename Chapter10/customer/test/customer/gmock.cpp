#include <gmock/gmock.h>

#include "customer/responder.h"

using namespace ::testing;

namespace {

class responder_mock {
 public:
  MOCK_METHOD(
      (std::pair<drogon::HttpStatusCode, Json::Value>),  // note the parentheses
      prepare_response, (const std::string &name), ());
  MOCK_METHOD(void, respond,
              (drogon::HttpStatusCode status, const Json::Value &response,
               std::function<void(const drogon::HttpResponsePtr &)> &&callback),
              ());
};

MATCHER_P(contains_value, value, "") { return arg == value; }

}  // namespace

TEST(basic_responses,
     given_name_when_handle_get_then_response_is_prepared_and_sent) {
  drogon::HttpRequestPtr request = drogon::HttpRequest::newHttpRequest();
  request->setMethod(drogon::HttpMethod::Get);
  request->setPath("/customer");
  request->setParameter("name", "Bob");

  auto responder = StrictMock<responder_mock>{};
  const auto response = Json::Value("my response");

  EXPECT_CALL(responder, prepare_response("Bob"))
      .WillOnce(Return(std::pair{drogon::k200OK, response}));
  EXPECT_CALL(responder, respond(drogon::k200OK, contains_value(response), _));

  handle_get(request, responder, [](const drogon::HttpResponsePtr &) {});
}
