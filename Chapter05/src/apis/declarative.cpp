#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <optional>
#include <ranges>
#include <string>
#include <vector>

std::optional<std::size_t> imperative_adjacent_distance() {
  constexpr auto temperatures = std::array{-3.0, 2.0, 0.0, 8.0, -10.0, -7.0};
  constexpr std::size_t size = temperatures.size();
  for (std::size_t i = 0; i < size - 1; ++i) {
    if (std::abs(temperatures[i] - temperatures[i + 1]) > 5) {
      return i;
    }
  }
  return std::nullopt;
}

std::optional<std::size_t> declarative_adjacent_distance() {
  constexpr auto temperatures = std::array{-3.0, 2.0, 0.0, 8.0, -10.0, -7.0};
  const auto it =
      std::ranges::adjacent_find(temperatures, [](double first, double second) {
        return std::abs(first - second) > 5;
      });
  if (it != std::end(temperatures)) {
    return std::distance(std::begin(temperatures), it);
  }
  return std::nullopt;
}

void modern_declarative() {
  using namespace std::literals;
  using namespace std::ranges;

  auto is_even = [](auto x) { return x % 2 == 0; };
  auto to_string = [](auto x) { return std::to_string(x); };
  auto my_range = views::iota(1) | views::filter(is_even) | views::take(2) |
                  views::reverse | views::transform(to_string);
  std::cout << std::accumulate(begin(my_range), end(my_range), ""s) << '\n';
}

int main() {
  if (const auto ret = imperative_adjacent_distance()) {
    std::cout << ret.value() << std::endl;
  }

  if (const auto ret = declarative_adjacent_distance()) {
    std::cout << ret.value() << std::endl;
  }

  modern_declarative();

  return 0;
}
