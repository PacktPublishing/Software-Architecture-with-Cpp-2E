#include <cstdint>
#include <string_view>

consteval uint64_t generate_lucky_number(std::string_view name) {
  uint64_t number = 1;
  for (const auto letter : name) {
    number = number * 7 + static_cast<uint64_t>(letter);
  }
  return number;
}

static_assert(generate_lucky_number("Paul and Jessica") == 491752089676924,
              "Generate the lucky number for Paul and Jessica");
