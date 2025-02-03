#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>
#include <format>
#include <ranges>
#include <vector>

using namespace std::ranges;

template <typename T>
auto make_sorted_vector(std::size_t size) {
  auto sorted = std::vector<T>{};
  sorted.reserve(size);

  auto sorted_view = views::iota(T{0}) | views::take(size);
  std::ranges::copy(sorted_view, std::back_inserter(sorted));
  return sorted;
}

constexpr auto MIN_HAYSTACK_SIZE = std::size_t{1'000};
constexpr auto MAX_HAYSTACK_SIZE = std::size_t{10'000'000};

void search_in_sorted_vector(const std::string &benchmarkName, std::size_t size,
                             int needle, auto finder) {
  auto haystack = make_sorted_vector<int>(size);

  BENCHMARK(std::format("{}/{}/{}", benchmarkName, needle, size)) {
    return finder(haystack, needle);
  };
}

void generate_sizes(const std::string &benchmarkName, auto finder) {
  for (std::size_t haystack = MIN_HAYSTACK_SIZE; haystack <= MAX_HAYSTACK_SIZE;
       haystack *= 100) {
    for (auto needle :
         {haystack / 8, haystack / 2, haystack - 1, haystack + 1}) {
      search_in_sorted_vector(benchmarkName, haystack, needle, finder);
    }
  }
}

TEST_CASE("binary_search_in_sorted_vector", "[benchmark]") {
  generate_sizes("lower_bound", lower_bound);
}

TEST_CASE("linear_search_in_sorted_vector", "[benchmark]") {
  generate_sizes("find", find);
}
