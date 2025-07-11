#include <gsl/assert>
#include <iostream>
#include <random>

int foobar(int n) {
  std::cout << "Expects that n >= 0: " << n << std::endl;
  Expects(n >= 0);

  ++n;

  std::cout << "Ensures that n < 10: " << n << std::endl;
  Ensures(n < 10);

  return n;
}

int main() {
  std::random_device rd;
  std::mt19937 gen{rd()};
  std::uniform_int_distribution<> dist{-5, 15};

  for (int i = 0; i < 5; ++i) {
    std::cout << "Value = " << foobar(dist(gen)) << std::endl;
  }
}
