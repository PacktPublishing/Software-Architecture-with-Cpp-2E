#include <array>
#include <bit>
#include <cassert>
#include <iostream>
#include <memory>

struct Point {
  double x, y;

  constexpr bool operator==(const Point &) const noexcept = default;
};

int main() {
  {
    char buffer[] = "into the eagle's nest";

    const auto p1 = new (buffer) char('I');
    const auto p2 = new (buffer + 9) char('E');
    const auto p3 = new (buffer + 17) char('N');

    std::cout << buffer << '\n' << *p1 << *p2 << *p3 << std::endl;
  }

  constexpr auto N = 51.528100;
  constexpr auto E = 45.977859;

  {
    alignas(Point) unsigned char buf[sizeof(Point)];
    Point *ptr = std::construct_at(reinterpret_cast<Point *>(buf), N, E);
    const bool res{*ptr == Point{N, E}};
    std::destroy_at(ptr);

    assert(res);
  }

  {
    alignas(Point) unsigned char buf[sizeof(Point)];
    auto p = std::bit_cast<Point>(buf);
    std::destroy_at(&p);

    Point *ptr = std::construct_at(std::addressof(p), N, E);
    const bool res{*ptr == Point{N, E}};
    std::destroy_at(ptr);

    assert(res);
  }
}
