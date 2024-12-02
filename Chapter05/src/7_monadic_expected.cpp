#include <expected>
#include <generator>
#include <iostream>
#include <print>
#include <string>

std::expected<int, std::string> parse_int(const std::string &s) {
  try {
    return std::stoi(s);
  } catch (std::exception &e) {
    return std::unexpected{"Invalid number"};
  }
}

std::generator<std::expected<std::string, std::string>> read_input_generator() {
  std::string s;
  while (true) {
    std::getline(std::cin, s);
    co_yield s;
  }
}

int main() {
  std::println("input numbers (press ^C to quit)");
  for (const auto &input : read_input_generator()) {
    auto res =
        input.and_then(parse_int)
            .transform([](const int n) { return n * n; })
            .transform([](const int n) { return std::to_string(n); })
            .transform_error([](const std::string &error) -> std::string {
              return "Error encountered: " + error;
            })
            .or_else([](const std::string &error) {
              std::println(std::cerr, "Handled Error ({})", error);
              // return
              // std::expected<std::string,std::string>(std::unexpected(error));
              return std::expected<std::string, std::string>{"*missing*"};
            });

    if (res.has_value()) {
      std::println("Square number: {}", *res);
    } else {
      std::println(std::cerr, "{}", res.error());
    }
  }

  return 0;
}