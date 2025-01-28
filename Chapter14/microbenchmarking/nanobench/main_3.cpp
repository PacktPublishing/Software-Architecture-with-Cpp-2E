#include <format>
#include <ranges>
#include <vector>

#define ANKERL_NANOBENCH_IMPLEMENT
#include <nanobench.h>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

using namespace std::ranges;

template <typename T>
auto make_sorted_vector(std::size_t size) {
  auto sorted = std::vector<T>{};
  sorted.reserve(size);

  auto sorted_view = views::iota(T{0}) | views::take(size);
  std::ranges::copy(sorted_view, std::back_inserter(sorted));
  return sorted;
}

#if !defined(_MSC_VER)
constexpr auto MIN_HAYSTACK_SIZE = 1'000uz;
constexpr auto MAX_HAYSTACK_SIZE = 10'000'000uz;
#else
constexpr auto MIN_HAYSTACK_SIZE = std::size_t{1'000};
constexpr auto MAX_HAYSTACK_SIZE = std::size_t{10'000'000};
#endif

void search_in_sorted_vector(const std::string &benchmarkName, auto finder) {
  for (std::size_t s = MIN_HAYSTACK_SIZE; s <= MAX_HAYSTACK_SIZE; s *= 10) {
    ankerl::nanobench::Bench().run(
        std::format("{}/{}", benchmarkName, s), [&]() {
          auto haystack = make_sorted_vector<int>(s);
          constexpr auto needle = 2137;
          ankerl::nanobench::doNotOptimizeAway(finder(haystack, needle));
        });
  }
}

TEST_CASE("binary_search_in_sorted_vector") {
  search_in_sorted_vector("binary_search_in_sorted_vector", lower_bound);
}

TEST_CASE("linear_search_in_sorted_vector") {
  search_in_sorted_vector("linear_search_in_sorted_vector", find);
}
