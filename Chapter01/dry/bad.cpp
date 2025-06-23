#include <iostream>

using namespace std;

int minimum(const int &x, const int &y) { return x < y ? x : y; }

double minimum(const double &x, const double &y) { return x < y ? x : y; }

int main() {
  cout << minimum(3, 5) << endl;
  cout << minimum(3.0, 5.0) << endl;

  return 0;
}
