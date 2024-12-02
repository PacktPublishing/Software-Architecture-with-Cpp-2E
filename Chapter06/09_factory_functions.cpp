#include <cstddef>

namespace factory_method {

class Pixel {
 public:
  static Pixel fromRgba(std::byte r, std::byte g, std::byte b, std::byte a) {
    return Pixel{r, g, b, a};
  }
  static Pixel fromBgra(std::byte b, std::byte g, std::byte r, std::byte a) {
    return Pixel{r, g, b, a};
  }

  // other members

 private:
  Pixel(std::byte r, std::byte g, std::byte b, std::byte a)
      : r_(r), g_(g), b_(b), a_(a) {}
  std::byte r_, g_, b_, a_;
};

}  // namespace factory_method

namespace factory_function {

struct Pixel {
  std::byte r, g, b, a;

 private:
  Pixel(std::byte r, std::byte g, std::byte b, std::byte a)
      : r(r), g(g), b(b), a(a) {}
  friend Pixel makePixelFromRgba(std::byte r, std::byte g, std::byte b,
                                 std::byte a);
  friend Pixel makePixelFromBgra(std::byte b, std::byte g, std::byte r,
                                 std::byte a);
};

Pixel makePixelFromRgba(std::byte r, std::byte g, std::byte b, std::byte a) {
  return Pixel{r, g, b, a};
}

Pixel makePixelFromBgra(std::byte b, std::byte g, std::byte r, std::byte a) {
  return Pixel{r, g, b, a};
}

}  // namespace factory_function

int main() {
  auto black_pixel = factory_method::Pixel::fromRgba(
      std::byte{0}, std::byte{0}, std::byte{0}, std::byte{0});
  auto white_pixel = factory_function::makePixelFromRgba(
      std::byte{255}, std::byte{255}, std::byte{255}, std::byte{0});
}
