#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <catch2/generators/catch_generators_range.hpp>
#include <format>
#include <memory>
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

void search_in_sorted_vector(const std::string& benchmarkName, std::size_t size,
                             auto finder) {
  auto haystack = make_sorted_vector<int>(size);
  constexpr auto needle = 2137;
  BENCHMARK(std::format("{}/{}", benchmarkName, size)) {
    return finder(haystack, needle);
  };
}

Catch::Generators::GeneratorWrapper<size_t> size_generator() {
  struct Generator final : Catch::Generators::IGenerator<size_t> {
    size_t cur{MIN_HAYSTACK_SIZE}, end{MAX_HAYSTACK_SIZE}, multiplier{10};

    const size_t& get() const override { return cur; }

    bool next() override {
      cur *= multiplier;
      return cur < end;
    }
  };

  return Catch::Generators::GeneratorWrapper<size_t>{
      Catch::Detail::make_unique<Generator>()};
}

TEST_CASE("binary_search_in_sorted_vector", "[benchmark]") {
  const auto size = GENERATE(size_generator());

  search_in_sorted_vector("lower_bound", size, lower_bound);
}

TEST_CASE("linear_search_in_sorted_vector", "[benchmark]") {
  const auto size = GENERATE(size_generator());

  search_in_sorted_vector("find", size, lower_bound);
}
