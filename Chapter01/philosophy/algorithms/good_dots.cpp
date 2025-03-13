#include <algorithm>
#include <string_view>

int count_dots(std::string_view str) {
  return std::count(str.begin(), str.end(), '.');
}
