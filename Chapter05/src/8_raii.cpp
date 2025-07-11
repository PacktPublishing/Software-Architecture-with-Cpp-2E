#include <algorithm>
#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <iterator>
#if __cplusplus >= 202002L
#include <span>
#endif

template <typename T> class Array final {
public:
  explicit Array(std::size_t size) : sz_{size}, data_{new T[size]()} {
    std::cout << "Resource acquired\n";
  }

  Array(std::initializer_list<T> list) : Array(list.size()) {
    std::copy(list.begin(), list.end(), data_);
  }

  ~Array() {
    delete[] data_;

    std::cout << "Resource released\n";
  }

  // copy constructors and assignment operator are deleted not to free
  // deallocated dynamic memory many times and to avoid shallow copying
  Array(const Array &) = delete;
  Array &operator=(const Array &) = delete;

  T &operator[](std::size_t idx) { return data_[idx]; }
  const T &operator[](std::size_t idx) const { return data_[idx]; }

  [[nodiscard]] std::size_t size() const noexcept { return sz_; }

#if __cplusplus >= 202002L
  std::span<const T> span() { return std::span{data_, sz_}; }
#endif

  struct Iterator {
#if __cplusplus < 202002L
    using iterator_category = std::forward_iterator_tag;
#endif
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

  [[nodiscard]] Iterator begin() { return Iterator(&data_[0]); }
  [[nodiscard]] Iterator end() { return Iterator(&data_[sz_]); }

  [[nodiscard]] const Iterator begin() const { return Iterator(&data_[0]); }
  [[nodiscard]] const Iterator end() const { return Iterator(&data_[sz_]); }

#if __cplusplus >= 202002L
  static_assert(std::forward_iterator<Iterator>);
#endif
private:
  std::size_t sz_;
  T *data_;
};

#if __cplusplus >= 202002L
template <typename T> void print_span(std::span<T> s) {
  std::copy(s.begin(), s.end(), std::ostream_iterator<T>(std::cout));
  std::cout << std::endl;
}
#endif

template <typename T> void print_array(const Array<T> &arr) {
  for (auto it = arr.begin(); it != arr.end(); ++it) {
    std::cout << *it;
  }
  std::cout << std::endl;
}

int main() {
  Array<char> arr{0x74, 0x68, 0x65, 0x20, 0x64, 0x6f, 0x6f, 0x72, 0x20, 0x69,
                  0x6e, 0x74, 0x6f, 0x20, 0x73, 0x75, 0x6d, 0x6d, 0x65, 0x72};

#if __cplusplus >= 202002L
  print_span(arr.span());
#else
  print_array(arr);
#endif

  for (std::size_t i{}; i < arr.size(); ++i) {
    arr[i] = static_cast<char>(i + 65);
  }

#if __cplusplus >= 202002L
  print_span(arr.span());
#else
  print_array(arr);
#endif

  for (auto &c : arr) {
    c += 32;
  }

  print_array(arr);

  // shallow and deep copying: try commenting deleted copy constructor and
  // assignment operator
  // Array<int> array{};
  // array = {1, 2, 3, 4, 5};
  // Array copy_array{array};
}
