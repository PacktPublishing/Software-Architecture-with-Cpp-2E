#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>
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

constexpr auto MAX_HAYSTACK_SIZE = std::size_t{10'000'000};
constexpr auto NEEDLE = 2137;

void search_in_sorted_vector(Catch::Benchmark::Chronometer &meter,
                             auto finder) {
  auto haystack = make_sorted_vector<int>(MAX_HAYSTACK_SIZE);
  meter.measure([&] { return finder(haystack, NEEDLE); });
}

TEST_CASE("binary_search_in_sorted_vector", "[benchmark]") {
  BENCHMARK_ADVANCED("lower_bound")(Catch::Benchmark::Chronometer meter) {
    search_in_sorted_vector(meter, lower_bound);
  };
}

TEST_CASE("linear_search_in_sorted_vector", "[benchmark]") {
  BENCHMARK_ADVANCED("find")(Catch::Benchmark::Chronometer meter) {
    search_in_sorted_vector(meter, find);
  };
}
