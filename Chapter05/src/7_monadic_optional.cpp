#include <iostream>
#include <optional>
#include <print>
#include <string>

#if !defined(_MSC_VER)
#include <generator>
#else
#include <experimental/generator>
#endif

std::optional<int> parse_int(const std::string &s) {
  try {
    return std::stoi(s);
  } catch (const std::exception &) {
    std::println(std::cerr, "{}", "Invalid number");
    return std::nullopt;
  }
}

#if !defined(_MSC_VER)
std::generator<std::optional<std::string>> read_input_generator() {
#else
std::experimental::generator<std::optional<std::string>>
read_input_generator() {
#endif
  std::string s;
  while (true) {
    std::getline(std::cin, s);
    co_yield std::make_optional(s);
  }
}

int main() {
  std::println("input numbers (press ^C to quit)");
  for (const auto &input : read_input_generator()) {
    auto res = input.and_then(parse_int)
                   .transform([](const int n) { return n * n; })
                   .transform([](const int n) { return std::to_string(n); })
                   .or_else([]() {
                     std::println(std::cerr, "Handled Error");
                     // return std::optional<std::string>();
                     return std::optional<std::string>{"*missing*"};
                   });

    if (res.has_value()) {
      std::println("Square number: {}", *res);
    } else {
      std::println(std::cerr, "no value");
    }
  }

  return 0;
}
