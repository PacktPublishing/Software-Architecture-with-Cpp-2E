#include <iostream>

using namespace std;

template <typename T> T minimum(const T &x, const T &y) {
  return x < y ? x : y;
}

int main() {
  cout << minimum(3, 5) << endl;
  cout << minimum(3.0, 5.0) << endl;

  return 0;
}
