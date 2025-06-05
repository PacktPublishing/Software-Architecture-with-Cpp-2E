#include <algorithm>
#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <span>
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

  std::span<const T> span() { return std::span{data, sz}; }

 private:
  std::size_t sz;
  T* data;
};

template <typename T>
void print_span(std::span<T> s) {
  std::copy(std::begin(s), std::end(s), std::ostream_iterator<T>(std::cout));
  std::cout << std::endl;
}

int main() {
  Array<char> arr{0x74, 0x68, 0x65, 0x20, 0x64, 0x6f, 0x6f, 0x72, 0x20, 0x69,
                  0x6e, 0x74, 0x6f, 0x20, 0x73, 0x75, 0x6d, 0x6d, 0x65, 0x72};

  print_span(arr.span());

  for (std::size_t i{}; i < arr.size(); ++i) {
    arr[i] = static_cast<char>(i + 65);
  }

  print_span(arr.span());
}
