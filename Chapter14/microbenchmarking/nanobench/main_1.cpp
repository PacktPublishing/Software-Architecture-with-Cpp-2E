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
constexpr auto MAX_HAYSTACK_SIZE = 10'000'000uz;
#else
constexpr auto MAX_HAYSTACK_SIZE = std::size_t{10'000'000};
#endif

constexpr auto NEEDLE = 2137;

TEST_CASE("binary_search_in_sorted_vector") {
  ankerl::nanobench::Bench().run("binary_search_in_sorted_vector", [&]() {
    auto haystack = make_sorted_vector<int>(MAX_HAYSTACK_SIZE);
    ankerl::nanobench::doNotOptimizeAway(lower_bound(haystack, NEEDLE));
  });
}

TEST_CASE("linear_search_in_sorted_vector") {
  ankerl::nanobench::Bench().run("linear_search_in_sorted_vector", [&]() {
    auto haystack = make_sorted_vector<int>(MAX_HAYSTACK_SIZE);
    ankerl::nanobench::doNotOptimizeAway(find(haystack, NEEDLE));
  });
}
