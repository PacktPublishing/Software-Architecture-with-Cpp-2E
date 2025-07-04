#include <array>
#include <cassert>
#include <iostream>
#include <memory>
#include <stdexcept>

struct Point final {
  double x, y;

  Point(double x, double y) : x(x), y(y) {
    std::cout << "Point(" << x << ',' << y << ')' << std::endl;
    // throw std::runtime_error("Point(): std::runtime_error");
  }
  Point() : Point(0, 0) { std::cout << "Point(0, 0)" << std::endl; }

  ~Point() { std::cout << "~Point()" << std::endl; }
};

void *operator new(std::size_t size, std::byte *buffer) {
  std::cout << "operator new " << size << " bytes" << std::endl;
  return ::operator new(size, static_cast<void *>(buffer));
}

void operator delete(void *ptr, std::byte *buffer) {
  std::cout << "operator delete at " << ptr << std::endl;
  ::operator delete(ptr, static_cast<void *>(buffer));
}

int main() {
  try {
    std::array<std::byte, 1024> buffer;
    auto *p1 = new (buffer.data()) Point{48.290178, 37.171792};
    p1->x = 52.194845;
    p1->y = 20.924213;
    const auto *p2 = new (&buffer[sizeof(Point)]) Point{53.946519, 27.688998};

    std::cout << "p1.x=" << p1->x << " p1.y=" << p1->y << std::endl;
    std::cout << "p2.x=" << p2->x << " p2.y=" << p2->y << std::endl;

    p1->~Point();
    p2->~Point();
  } catch (const std::exception &ex) {
    std::cout << ex.what() << '\n';
  }
}
