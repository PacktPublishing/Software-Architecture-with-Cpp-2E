#include <iostream>
#include <string>

int main() {
  std::string s("sample");
  const char *p = s.data();
  {
    std::string copy = s;
    std::cout << s[0] << std::endl; // COW triggers memory reallocation
  }
  std::cout << *p << '\n'; // p is dangling
}
