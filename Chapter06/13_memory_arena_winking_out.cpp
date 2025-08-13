#include <cstddef>
#include <iostream>
#include <memory_resource>
#include <new>
#include <string>

struct Test final {
  std::string name;

  explicit Test(std::string n) : name(std::move(n)) {
    std::cout << "Constructed: " << name << '\n';
  }

  ~Test() { std::cout << "Destructed: " << name << '\n'; }
};

int main() {
  std::cout << "Creating arena and constructing objects manually...\n";

  std::byte buffer[1024];
  std::pmr::monotonic_buffer_resource arena{buffer, sizeof(buffer)};

  void *mem1 = arena.allocate(sizeof(Test), alignof(Test));
  new (mem1) Test("Alpha");

  void *mem2 = arena.allocate(sizeof(Test), alignof(Test));
  new (mem2) Test("Beta");

  std::cout << "Constructed 2 objects. Exiting scope...\n";

  // No destructors are called!
}
