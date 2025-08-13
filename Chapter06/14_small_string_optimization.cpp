#include <algorithm>
#include <cstddef>
#include <cstring>
#include <iostream>
#include <stdexcept>

class String final {
  static const std::size_t BUF_SIZE = 15;

  union {
    char buffer[BUF_SIZE + 1];
    char *data;
  };
  std::size_t size{};

  [[nodiscard]] bool is_small_string() const noexcept {
    return size <= BUF_SIZE;
  }

public:
  explicit String(const char *s) {
    size = strlen(s);
    data = !is_small_string() ? new char[size] : buffer;
    memcpy(data, s, size + 1);
  };

  ~String() {
    if (!is_small_string()) {
      delete[] data;
    }
  }

  String(const String &other) { *this = other; }

  String &operator=(const String &other) {
    if (this != &other) {
      if (!is_small_string()) {
        delete[] data;
      }

      size = other.size;
      if (!is_small_string()) {
        data = new char[size];
        memcpy(data, other.data, size + 1);
      } else {
        memcpy(buffer, other.buffer, size + 1);
      }
    }
    return *this;
  };

  String(String &&other) noexcept { *this = std::move(other); }

  String &operator=(String &&other) noexcept {
    if (this != &other) {
      size = other.size;
      if (!is_small_string()) {
        data = other.data;
      } else {
        memcpy(buffer, other.buffer, size + 1);
      }

      other.size = 0;
      other.data = nullptr;
    }
    return *this;
  }

  char &operator[](std::size_t idx) {
    return !is_small_string() ? data[idx] : buffer[idx];
  }
  char operator[](std::size_t idx) const {
    return !is_small_string() ? data[idx] : buffer[idx];
  }

  [[nodiscard]] std::size_t length() const noexcept { return size; }

  friend std::ostream &operator<<(std::ostream &os, const String &s) {
    os << (!s.is_small_string() ? s.data : s.buffer);
    return os;
  }
};

int main() {
  {
    const String s1{"Look sharp!"};
    const String s2{"You know she's a little bit dangerous"};

    std::cout << "s1=" << s1 << "\ns2=" << s2 << std::endl;
  }

  {
    String a{"Hungry eyes"};
    a = a;
    const String b = std::move(a);

    std::cout << "a=" << a << "\nb=" << b << std::endl;
  }

  {
    String a{"Don't you, forget about me"};
    a = std::move(a); // intentional
    const String b = a;
    const String c{std::move(a)};

    std::cout << "a=" << a << "\nb=" << b << "\nc=" << c << std::endl;
  }

  {
    String a{""};
    const String b = a;
    const String c{std::move(a)};

    std::cout << "a=" << a << "\nb=" << b << "\nc=" << c << std::endl;
  }

  try {
    String a{"Miód   , marcepan, kwiatów cały pęk"};

    const std::string b{"Şinanay"};
    int i = 100; // not 0
    for (auto c : b) {
      a[i++] = c;
    }
    std::cout << "a=" << a << "\nb=" << b << std::endl;
  } catch (const std::out_of_range &e) {
    std::cerr << e.what() << std::endl;
  }
}
