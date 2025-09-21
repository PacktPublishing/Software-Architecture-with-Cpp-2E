#include <iostream>
#include <map>
#include <string>

#ifndef __has_cpp_attribute
#define lifetime_bound
#elif __has_cpp_attribute(clang::lifetimebound)
#define lifetime_bound [[clang::lifetimebound]]
#elif __has_cpp_attribute(msvc::lifetimebound)
#define lifetime_bound [[msvc::lifetimebound]]
#elif __has_cpp_attribute(lifetimebound)
#define lifetime_bound [[lifetimebound]]
#else
#define lifetime_bound
#endif

using namespace std::literals;

template <typename T, typename U>
const U &get_or_default(const std::map<T, U> &m lifetime_bound, const T &key,
                        const U &default_value lifetime_bound) {
  if (auto iter = m.find(key); iter != m.end())
    return iter->second;
  return default_value;
}

int main() {
  const std::map<std::string, std::string> m;

  // warning: temporary bound to local reference 'val1' will be destroyed at the
  // end of the full-expression
  const std::string &val1 = get_or_default(m, "vault"s, "11"s);
  std::cout << val1 << std::endl;

  // no warning
  const auto def_val = "13"s;
  const std::string &val2 = get_or_default(m, "vault"s, def_val);
  std::cout << val2 << std::endl;

  return 0;
}
