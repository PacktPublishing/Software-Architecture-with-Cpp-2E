#include <iostream>
// C Standard General Utilities Library
#include <cstdlib>

// C style cast
int comp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

template <typename T> class strong_typedef {
public:
  explicit strong_typedef(T val) : value_(val) {}

  explicit operator T() const noexcept { return value_; }

private:
  T value_;
};

class number : public strong_typedef<size_t> {
public:
  explicit number(size_t val) : strong_typedef(val) {}
};

class width : public strong_typedef<size_t> {
public:
  explicit width(size_t val) : strong_typedef(val) {}
};

void safe_qsort(void *ptr, const number &number, const width &width,
                int (*comp)(const void *, const void *)) {
  qsort(ptr, static_cast<size_t>(number), static_cast<size_t>(width), comp);
}

int main() {
  {
    int arr[] = {5, 4, 3, 2, 1};
    const int n = sizeof(arr) / sizeof(arr[0]);

    // https://en.cppreference.com/w/c/algorithm/qsort
    // void qsort(void* ptr, size_t number, size_t width,
    //            int (*comp)(const void*, const void*));

    // correct order: 1 2 3 4 5
    // qsort(arr, n, sizeof(int), comp);

    // oops, it can be on x86-64: 5 65540 0 2 196608
    // the array looks like a mangled mess
    qsort(arr, sizeof(int), n, comp);

    for (int i = 0; i < n; ++i) {
      std::cout << arr[i] << ' ';
    }
  }

  std::cout << std::endl;

  {
    int arr[] = {5, 4, 3, 2, 1};
    constexpr int n = sizeof(arr) / sizeof(arr[0]);

    // compile error: no known conversion from 'width' to 'number'
    // safe_qsort(arr, width{sizeof(int)}, number{n}, comp);
    safe_qsort(arr, number{n}, width{sizeof(int)}, comp);

    for (int i : arr) {
      std::cout << i << ' ';
    }
  }

  return 0;
}
