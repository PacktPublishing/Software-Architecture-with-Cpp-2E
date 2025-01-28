#include <boost/asio.hpp>
#include <boost/cobalt.hpp>
#include <chrono>
#include <print>
#include <random>
#include <thread>
#include <vector>

using namespace boost;

inline constexpr auto WORK_ITEMS = 5;

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> distrib(0, 800);

cobalt::task<void> fill_number(int i, std::vector<int> &ints,
                               cobalt::channel<void> &mutex) {
  std::println("Thread {}: producing {}", std::this_thread::get_id(), i);
  asio::steady_timer timer{cobalt::this_thread::get_executor(),
                           std::chrono::milliseconds(distrib(gen))};
  co_await timer.async_wait(cobalt::use_op);

  {
    // remember to co_await!
    co_await mutex.write();
    ints.emplace_back(i);
    co_await mutex.read();
  }

  std::println("Thread {}: produced {}", std::this_thread::get_id(), i);
  co_return;
}

cobalt::task<std::vector<int>> do_routine_work() {
  cobalt::channel<void> mutex{1, cobalt::this_thread::get_executor()};
  auto ints = std::vector<int>{};
  ints.reserve(WORK_ITEMS);

  std::println("Thread {}: passing execution to the pool",
               std::this_thread::get_id());

  std::println("Thread {}: running first pooled job",
               std::this_thread::get_id());

  std::vector<cobalt::task<void>> tasks;
  tasks.reserve(WORK_ITEMS);

  for (int i = 0; i < WORK_ITEMS; ++i) {
    tasks.emplace_back(fill_number(i, ints, mutex));
  }

  co_await cobalt::gather(std::move(tasks));

  co_return ints;
}

cobalt::main co_main(int argc, char *argv[]) {
  auto executor = co_await cobalt::this_coro::executor;

  std::println("Thread {}: preparing work", std::this_thread::get_id());
  auto work = do_routine_work();

  std::println("Thread {}: starting work", std::this_thread::get_id());
  const auto ints = run(std::move(work));

  std::print("Thread {}: work done.\nProduced ints are: ",
             std::this_thread::get_id());
  for (auto i : ints) {
    std::print("{}, ", i);
  }
  std::println();

  co_return 0;
}
