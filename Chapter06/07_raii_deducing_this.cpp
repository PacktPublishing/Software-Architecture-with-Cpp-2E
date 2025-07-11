#include <algorithm>
#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <iterator>

template <typename T> class Array final {
public:
  explicit Array(std::size_t size) : sz_{size}, data_{new T[size]()} {}

  Array(std::initializer_list<T> list) : Array(list.size()) {
    std::copy(list.begin(), list.end(), data_);
  }

  ~Array() { delete[] data_; }

  Array(const Array &other) { *this = other; }

  Array &operator=(const Array &other) {
    if (this != &other) {
      delete[] data_;

      sz_ = other.sz_;
      data_ = new T[other.sz_];

      std::copy(other.begin(), other.end(), data_);
    }
    return *this;
  };

  Array(Array &&other) noexcept { *this = std::move(other); }

  Array &operator=(Array &&other) noexcept {
    if (this != &other) {
      sz_ = other.sz_;
      data_ = other.data_;

      other.sz_ = 0;
      other.data_ = nullptr;
    }
    return *this;
  }

  // Use an explicit object parameter (self) and auto&&
  // to differentiate const vs non-const
  auto &&operator[](this auto &&self, std::size_t idx) {
    return self.data_[idx];
  }

  [[nodiscard]] std::size_t size() const noexcept { return sz_; }

  struct Iterator {
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using pointer = T *;
    using reference = T &;

    Iterator() = default;

    explicit Iterator(pointer ptr) : ptr_{ptr} {}

    reference operator*() const { return *ptr_; }
    pointer operator->() { return ptr_; }

    Iterator &operator++() {
      ++ptr_;
      return *this;
    }
    Iterator operator++(int) {
      Iterator tmp = *this;
      ++(*this);
      return tmp;
    }
    friend bool operator==(const Iterator &a, const Iterator &b) {
      return a.ptr_ == b.ptr_;
    };
    friend bool operator!=(const Iterator &a, const Iterator &b) {
      return a.ptr_ != b.ptr_;
    };

  private:
    pointer ptr_{nullptr};
  };

  [[nodiscard]] Iterator begin(this auto &&self) {
    return Iterator(&self.data_[0]);
  }
  [[nodiscard]] Iterator end(this auto &&self) {
    return Iterator(&self.data_[self.sz_]);
  }

  static_assert(std::forward_iterator<Iterator>);

private:
  std::size_t sz_;
  T *data_{nullptr};
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
  a = std::move(a);
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

  // shallow and deep copying
  Array<int> array{};
  array = {1, 2, 3, 4, 5};
  std::cout << "array:\n" << array << std::endl;
}
