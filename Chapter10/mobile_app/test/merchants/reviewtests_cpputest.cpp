#include "fake_customer_review_store.h"
#include "merchants/reviews.h"
#include "merchants/visited_merchant_history.h"

// clang-format off
#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
// clang-format on

namespace {
class mock_visited_merchant final : public i_visited_merchant {
 public:
  explicit mock_visited_merchant(fake_customer_review_store &store,
                                 const merchant_id_t id)
      : review_store_{store},
        review_{store.get_review_for_merchant(id).value()} {}

  stars get_rating() override { return review_.rating; }

  void post_rating(const stars s) override {
    mock().actualCall(__func__).onObject(this);
    review_.rating = s;
    review_store_.post_review(review_);
  }

 private:
  fake_customer_review_store &review_store_;
  review review_;
};
}  // namespace

TEST_GROUP(history_with_one_rated_merchant) {
  static constexpr std::size_t CUSTOMER_ID = 7777;
  static constexpr std::size_t MERCHANT_ID = 1234;
  static constexpr const char *REVIEW_TEXT = "Very nice!";
  static constexpr stars RATING = stars{5.f};

  TEST_SETUP() {
    fake_review_store_.post_review(
        {CUSTOMER_ID, MERCHANT_ID, REVIEW_TEXT, RATING});

    merchant_index_ = history_.add(std::make_unique<mock_visited_merchant>(
        fake_review_store_, MERCHANT_ID));
  }

  TEST_TEARDOWN() {
    mock().checkExpectations();
    mock().clear();
  }

  fake_customer_review_store fake_review_store_{CUSTOMER_ID};
  history_of_visited_merchants history_{};
  std::size_t merchant_index_{};
};

TEST(history_with_one_rated_merchant, history_with_one_rated_merchant) {
  const auto &mocked_merchant = history_.get_merchant(merchant_index_);
  mock()
      .expectOneCall("post_rating")
      .onObject(const_cast<i_visited_merchant *>(&mocked_merchant));

  constexpr auto new_rating = stars{4};
  static_assert(RATING != new_rating);
  history_.rate(merchant_index_, stars{new_rating});
}

TEST(history_with_one_rated_merchant,
     when_user_changes_rating_then_the_review_is_updated_in_store) {
  const auto &mocked_merchant = history_.get_merchant(merchant_index_);
  mock()
      .expectNCalls(0, "post_rating")
      .onObject(const_cast<i_visited_merchant *>(&mocked_merchant));

  history_.rate(merchant_index_, stars{RATING});
}

int main(const int ac, char **av) { return RUN_ALL_TESTS(ac, av); }
