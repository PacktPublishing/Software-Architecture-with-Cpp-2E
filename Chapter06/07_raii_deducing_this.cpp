#include <algorithm>
#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <numeric>
#include <ranges>
#include <stdexcept>

template <typename T> class Array {
public:
  explicit Array(std::size_t size) : sz{size}, data{new T[size]()} {}

  Array(std::initializer_list<T> l) : Array(l.size()) {
    std::copy(l.begin(), l.end(), data);
  }

  Array(const Array &other) { *this = other; }

  Array &operator=(const Array &other) {
    if (this != &other) {
      sz = other.sz;
      data = new T[other.sz];

      std::copy(other.begin(), other.end(), data);
    }
    return *this;
  };

  Array(Array &&other) noexcept { *this = std::move(other); }

  Array &operator=(Array &&other) noexcept {
    if (this != &other) {
      sz = other.sz;
      data = other.data;

      other.sz = 0;
      other.data = nullptr;
    }
    return *this;
  }

  // Use an explicit object parameter (self) and auto&&
  // to differentiate const vs non-const
  auto &&operator[](this auto &&self, std::size_t idx) {
    if (idx >= self.sz)
      throw std::out_of_range("Index is out of range");
    return self.data[idx];
  }

  [[nodiscard]] std::size_t size() const { return sz; }

  struct Iterator {
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using pointer = T *;
    using reference = T &;

    Iterator() = default;

    explicit Iterator(pointer ptr) : ptr(ptr) {}

    reference operator*() const { return *ptr; }
    pointer operator->() { return ptr; }

    Iterator &operator++() {
      ++ptr;
      return *this;
    }
    Iterator operator++(int) {
      Iterator tmp = *this;
      ++(*this);
      return tmp;
    }
    friend bool operator==(const Iterator &a, const Iterator &b) {
      return a.ptr == b.ptr;
    };
    friend bool operator!=(const Iterator &a, const Iterator &b) {
      return a.ptr != b.ptr;
    };

  private:
    pointer ptr;
  };

  Iterator begin(this auto &&self) { return Iterator(&self.data[0]); }
  Iterator end(this auto &&self) { return Iterator(&self.data[self.sz]); }

  static_assert(std::forward_iterator<Iterator>);

private:
  std::size_t sz;
  T *data;
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const Array<T> &arr) {
  os << '[';
  bool flag = false;
  for (auto v : arr) {
    if (flag)
      os << ',';
    os << v;
    flag = true;
  }
  os << ']';
  return os;
}

int main() {
  Array<int> a(10);
  std::ranges::iota(a, 1);

  a = a;
  std::cout << "iota:\n" << "a=" << a << std::endl;

  const Array d = a;
  Array b(a), c = b;

  std::cout << "copy:\na=" << a << "\nb=" << b << "\nc=" << c << "\nd=" << d
            << std::endl;

  Array e = std::move(b);
  Array f(std::move(c));

  std::ranges::for_each(e, [](auto &v) { v *= 2; });
  std::ranges::for_each(f, [](auto &v) { v *= 4; });

  a = std::move(a);
  std::cout << "move:\na=" << a << "\nb=" << b << "\nc=" << c << "\ne=" << e
            << "\nf=" << f << std::endl;
}
