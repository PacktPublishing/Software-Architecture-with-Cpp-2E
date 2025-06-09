#include <algorithm>
#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <iterator>
#if __cplusplus >= 202002L
#include <span>
#endif
#include <stdexcept>

template <typename T>
class Array {
 public:
  explicit Array(std::size_t size) : sz{size}, data{new T[size]()} {
    std::cout << "Resource acquired\n";
  }

  Array(std::initializer_list<T> l) : Array(l.size()) {
    std::copy(l.begin(), l.end(), data);
  }

  ~Array() {
    delete[] data;

    std::cout << "Resource released\n";
  }

  // not to release the acquired dynamic memory again
  Array(const Array&) = delete;
  Array& operator=(const Array&) = delete;

  T& operator[](std::size_t idx) {
    if (idx >= sz) throw std::out_of_range("Index is out of range");
    return data[idx];
  }
  const T& operator[](std::size_t idx) const {
    if (idx >= sz) throw std::out_of_range("Index is out of range");
    return data[idx];
  }

  [[nodiscard]] std::size_t size() const { return sz; }

#if __cplusplus >= 202002L
  std::span<const T> span() { return std::span{data, sz}; }
#endif

  struct Iterator {
#if __cplusplus < 202002L
    using iterator_category = std::forward_iterator_tag;
#endif
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using pointer = T*;
    using reference = T&;

    Iterator() = default;

    explicit Iterator(pointer ptr) : ptr(ptr) {}

    reference operator*() const { return *ptr; }
    pointer operator->() { return ptr; }

    Iterator& operator++() {
      ++ptr;
      return *this;
    }
    Iterator operator++(int) {
      Iterator tmp = *this;
      ++(*this);
      return tmp;
    }
    friend bool operator==(const Iterator& a, const Iterator& b) {
      return a.ptr == b.ptr;
    };
    friend bool operator!=(const Iterator& a, const Iterator& b) {
      return a.ptr != b.ptr;
    };

   private:
    pointer ptr;
  };

  Iterator begin() { return Iterator(&data[0]); }
  Iterator end() { return Iterator(&data[sz]); }

  [[nodiscard]] Iterator begin() const { return Iterator(&data[0]); }
  [[nodiscard]] Iterator end() const { return Iterator(&data[sz]); }

#if __cplusplus >= 202002L
  static_assert(std::forward_iterator<Iterator>);
#endif
 private:
  std::size_t sz;
  T* data;
};

#if __cplusplus >= 202002L
template <typename T>
void print_span(std::span<T> s) {
  std::copy(std::begin(s), std::end(s), std::ostream_iterator<T>(std::cout));
  std::cout << std::endl;
}
#endif

template <typename T>
void print_array(const Array<T>& arr) {
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

  for (auto& c : arr) {
    c += 32;
  }

  print_array(arr);
}
