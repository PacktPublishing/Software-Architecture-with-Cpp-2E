#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <random>
#include <ranges>
#include <utility>

#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>

enum class op_code {
  OP_HALT = 0x00,
  OP_INC = 0x01,
  OP_DEC = 0x02,
  OP_MUL2 = 0x03,
  OP_DIV2 = 0x04,
  OP_REM2 = 0x05,
  OP_NEG = 0x06,
  OP_SENTINEL = OP_NEG
};

namespace switch_vm {
int64_t bytecode_interpreter(const op_code *bytecode, int64_t init_val) {
  int64_t val = init_val;
  std::size_t pc = 0;

  while (true) {
    switch (bytecode[pc++]) {
    case op_code::OP_HALT:
      return val;
    case op_code::OP_INC:
      ++val;
      break;
    case op_code::OP_DEC:
      --val;
      break;
    case op_code::OP_MUL2:
      val *= 2;
      break;
    case op_code::OP_DIV2:
      val /= 2;
      break;
    case op_code::OP_REM2:
      val %= 2;
      break;
    case op_code::OP_NEG:
      val = -val;
      break;
    default:
      return val;
    }
  }
}
} // namespace switch_vm

namespace computed_goto_vm {
int64_t bytecode_interpreter(const op_code *bytecode, int64_t init_val) {
  static void *dispatch[] = {&&TARGET_HALT, &&TARGET_INC,  &&TARGET_DEC,
                             &&TARGET_MUL2, &&TARGET_DIV2, &&TARGET_REM2,
                             &&TARGET_NEG};

#define DISPATCH() goto *dispatch[std::to_underlying(bytecode[pc++])];

  int64_t val = init_val;
  std::size_t pc = 0;

  DISPATCH()

TARGET_HALT: { return val; }
TARGET_INC: {
  ++val;
  DISPATCH()
}

TARGET_DEC: {
  --val;
  DISPATCH()
}

TARGET_MUL2: {
  val *= 2;
  DISPATCH()
}

TARGET_DIV2: {
  val /= 2;
  DISPATCH()
}

TARGET_REM2: {
  val %= 2;
  DISPATCH()
}

TARGET_NEG: {
  val = -val;
  DISPATCH()
}
}
} // namespace computed_goto_vm

TEST_CASE("virtual_machine", "[benchmark]") {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib(
      0, static_cast<int>(op_code::OP_SENTINEL));

  constexpr auto SIZE = 1 << 24;
  auto bytecode = std::unique_ptr<op_code[]>(new op_code[SIZE]);
  std::generate_n(bytecode.get(), SIZE, [&distrib, &gen]() {
    return static_cast<op_code>(distrib(gen));
  });
  bytecode[SIZE - 1] = op_code::OP_HALT;

  BENCHMARK_ADVANCED("switch_vm")(Catch::Benchmark::Chronometer meter) {
    meter.measure(
        [&] { return switch_vm::bytecode_interpreter(bytecode.get(), 0); });
  };

  BENCHMARK_ADVANCED("computed_goto_vm")(Catch::Benchmark::Chronometer meter) {
    meter.measure([&] {
      return computed_goto_vm::bytecode_interpreter(bytecode.get(), 0);
    });
  };
}
