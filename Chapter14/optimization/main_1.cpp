#include <cstdint>

#include <benchmark/benchmark.h>

using namespace std;

namespace iteration {
uint64_t factorial(uint32_t n) {
  uint64_t res = 1;
  for (auto i = 1; i <= n; ++i) {
    res *= i;
  }
  return res;
}

uint64_t fibonacci(uint32_t n) {
  uint64_t b = 0, a = 1, res = 0;
  for (auto i = 2; i <= n; ++i) {
    res = b + a;
    b = a;
    a = res;
  }
  return res;
}
} // namespace iteration

namespace recursion {
uint64_t factorial(uint32_t n) {
  if (n == 0) {
    return 1;
  }
  return n * factorial(n - 1);
}

uint64_t fibonacci(uint32_t n) {
  if (n < 2) {
    return n;
  }

  return fibonacci(n - 2) + fibonacci(n - 1);
}
} // namespace recursion

#ifndef __has_cpp_attribute
#define musttail
#elif __has_cpp_attribute(clang::musttail)
#define musttail [[clang::musttail]]
#elif __has_cpp_attribute(musttail)
#define musttail [[musttail]]
#else
#define musttail
#endif

namespace tail_recursion {
namespace { // anonymous namespace
uint64_t factorial(uint32_t n, uint64_t a) {
  if (n == 1) {
    return a;
  }
  musttail return factorial(n - 1, a * n);
}

uint64_t fibonacci(uint32_t n, uint64_t a, uint64_t b) {
  if (n == 0) {
    return a;
  }
  if (n == 1) {
    return b;
  }
  musttail return fibonacci(n - 1, b, a + b);
}
} // anonymous namespace

uint64_t factorial(uint32_t n) { return factorial(n, 1); }

uint64_t fibonacci(uint32_t n) { return fibonacci(n, 0, 1); }
} // namespace tail_recursion

void BM_test(benchmark::State &state, auto func) {
  const auto n = state.range(0);
  for (auto _ : state) {
    benchmark::DoNotOptimize(func(n));
  }
}

namespace {

constexpr auto MIN_FACTORIAL = 32768;
constexpr auto MAX_FACTORIAL = 65536;

BENCHMARK_CAPTURE(BM_test, iteration::factorial, iteration::factorial)
    ->RangeMultiplier(2)
    ->Range(MIN_FACTORIAL, MAX_FACTORIAL);
BENCHMARK_CAPTURE(BM_test, recursion::factorial, recursion::factorial)
    ->RangeMultiplier(2)
    ->Range(MIN_FACTORIAL, MAX_FACTORIAL);
BENCHMARK_CAPTURE(BM_test, tail_recursion::factorial, tail_recursion::factorial)
    ->RangeMultiplier(2)
    ->Range(MIN_FACTORIAL, MAX_FACTORIAL);

constexpr auto MIN_FIBONACCI = 16;
constexpr auto MAX_FIBONACCI = 32;

BENCHMARK_CAPTURE(BM_test, iteration::fibonacci, iteration::fibonacci)
    ->RangeMultiplier(2)
    ->Range(MIN_FIBONACCI, MAX_FIBONACCI);
BENCHMARK_CAPTURE(BM_test, recursion::fibonacci, recursion::fibonacci)
    ->RangeMultiplier(2)
    ->Range(MIN_FIBONACCI, MAX_FIBONACCI);
BENCHMARK_CAPTURE(BM_test, tail_recursion::fibonacci, tail_recursion::fibonacci)
    ->RangeMultiplier(2)
    ->Range(MIN_FIBONACCI, MAX_FIBONACCI);

} // namespace

BENCHMARK_MAIN();
