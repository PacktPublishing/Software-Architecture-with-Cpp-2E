#include <expected>
#include <iostream>
#include <print>
#include <stdexcept>
#include <string>

std::expected<int, std::string> parse_int(const std::string &s) {
  try {
    std::println("Parsing {} to integer", s);
    return std::stoi(s);
  } catch (const std::invalid_argument &ex) {
    std::println(std::cerr, "std::invalid_argument::what(): {}", ex.what());
    return std::unexpected{"invalid argument"};
  } catch (std::out_of_range const &ex) {
    std::println(std::cerr, "std::out_of_range::what(): {}", ex.what());
    return std::unexpected{"out of range"};
  }
}

int main() {
  std::println("Input integers (press ^C to quit)");

  while (true) {
    std::string s;
    std::getline(std::cin, s);
    auto input = std::expected<std::string, std::string>(s);

    auto res =
        input.and_then(parse_int)
            .transform([](int n) {
              std::println("Squaring {}", n);
              return n * n;
            })
            .transform([](int n) {
              std::println("Converting {} to a string", n);
              return std::to_string(n);
            })
            .transform_error([](const std::string &error) -> std::string {
              return "Error encountered: " + error;
            })
            .or_else([](const std::string &error) {
              std::println(std::cerr, "Handled error ({})", error);
              return std::expected<std::string, std::string>(
                  std::unexpected(error));
            });

    if (res.has_value()) {
      std::println("Square number: {}", *res);
    } else {
      std::println(std::cerr, "{}", res.error());
    }
  }
}
