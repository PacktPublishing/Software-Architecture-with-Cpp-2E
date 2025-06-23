#include <iostream>
#include <optional>
#include <print>
#include <stdexcept>
#include <string>

std::optional<int> parse_int(const std::string &s) {
  try {
    std::println("Parsing {} to integer", s);
    return std::stoi(s);
  } catch (const std::invalid_argument &ex) {
    std::println(std::cerr, "std::invalid_argument::what(): {}", ex.what());
    return std::nullopt;
  } catch (const std::out_of_range &ex) {
    std::println(std::cerr, "std::out_of_range::what(): {}", ex.what());
    return std::nullopt;
  }
}

int main() {
  std::println("Input integers (press ^C to quit)");

  while (true) {
    std::string s;
    std::getline(std::cin, s);
    auto input = std::make_optional(s);

    auto res = input.and_then(parse_int)
                   .transform([](int n) {
                     std::println("Squaring {}", n);
                     return n * n;
                   })
                   .transform([](int n) {
                     std::println("Converting {} to a string", n);
                     return std::to_string(n);
                   })
                   .or_else([]() {
                     std::println(std::cerr, "Handled error");
                     return std::optional<std::string>{"*missing*"};
                   });

    if (res.has_value()) {
      std::println("Square number: {}", *res);
    } else {
      std::println(std::cerr, "no value");
    }
  }
}
