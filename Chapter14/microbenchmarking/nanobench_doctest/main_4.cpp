#include <format>
#include <iostream>
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

void search_in_sorted_vector(ankerl::nanobench::Bench &bench,
                             const std::string &benchmarkName,
                             const std::size_t size, int needle, auto finder) {
  bench.complexityN(size).run(
      std::format("{}/{}/{}", benchmarkName, needle, size), [&]() {
        auto haystack = make_sorted_vector<int>(size);
        ankerl::nanobench::doNotOptimizeAway(finder(haystack, needle));
      });
}

void generate_sizes(ankerl::nanobench::Bench &bench,
                    const std::string &benchmarkName, auto finder) {
  for (std::size_t haystack = MIN_HAYSTACK_SIZE; haystack <= MAX_HAYSTACK_SIZE;
       haystack *= 100) {
    for (auto needle :
         {haystack / 8, haystack / 2, haystack - 1, haystack + 1}) {
      search_in_sorted_vector(bench, benchmarkName, haystack, needle, finder);
    }
  }
}

TEST_CASE("binary_search_in_sorted_vector") {
  ankerl::nanobench::Bench bench;
  generate_sizes(bench, "binary_search_in_sorted_vector", lower_bound);
  std::cout << bench.complexityBigO() << std::endl;
}

TEST_CASE("linear_search_in_sorted_vector") {
  ankerl::nanobench::Bench bench;
  generate_sizes(bench, "linear_search_in_sorted_vector", find);
  std::cout << bench.complexityBigO() << std::endl;
}
