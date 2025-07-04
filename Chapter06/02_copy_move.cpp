#include <algorithm>

struct NonCopyable {
  NonCopyable() = default;
  NonCopyable(const NonCopyable &) = delete;
  NonCopyable &operator=(const NonCopyable &) = delete;
  // NOTE: also non-movable
  // without defined move constructor and assignment operator
  // NonCopyable(NonCopyable &&) = default;
  // NonCopyable &operator=(NonCopyable &&) = default;
  virtual ~NonCopyable() = default;
};

class MyType : NonCopyable {};

struct MyTypeV2 {
  MyTypeV2() = default;
  MyTypeV2(const MyTypeV2 &) = delete;
  MyTypeV2 &operator=(const MyTypeV2 &) = delete;
  MyTypeV2(MyTypeV2 &&) = delete;
  MyTypeV2 &operator=(MyTypeV2 &&) = delete;
  virtual ~MyTypeV2() = default;
};

int main() {
  // in C++17+ this works despite non-copyablility due to mandatory copy elision
  auto my_object = MyType{};
  auto my_better_object = MyTypeV2{};

  /* clang-format off */
  // auto my_object2 = my_object;  // compilation error: non-copyable
  // auto my_object3{my_object};  // compilation error: non-copyable
  // auto my_object2 = std::move(my_object);  // compilation error: non-moveable, but can be
  // auto my_object3{std::move(my_object)};   // compilation error: non-moveable, but can be

  //auto my_better_object2= my_better_object;  // compilation error: non-copyable
  //auto my_better_object3{my_better_object};  // compilation error: non-copyable
  //auto my_better_object4= std::move(my_better_object);  // compilation error: non-moveable
  //auto my_better_object5{std::move(my_better_object)};  // compilation error: non-moveable
  /* clang-format on */
}
