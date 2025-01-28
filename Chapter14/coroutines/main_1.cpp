#include <chrono>
#include <coro/coro.hpp>
#include <print>
#include <random>
#include <thread>
#include <vector>

inline constexpr auto WORK_ITEMS = 5;

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> distrib(0, 800);

coro::task<> fill_number(int i, std::vector<int> &ints,
                         coro::thread_pool &thread_pool, coro::mutex &mutex) {
  co_await thread_pool.schedule();

  std::println("Thread {}: producing {}", std::this_thread::get_id(), i);
  std::this_thread::sleep_for(std::chrono::milliseconds(distrib(gen)));

  {
    // remember to co_await!
    auto lock = co_await mutex.lock();
    ints.emplace_back(i);
  }

  std::println("Thread {}: produced {}", std::this_thread::get_id(), i);
  co_return;
}

coro::task<std::vector<int>> do_routine_work(coro::thread_pool &thread_pool) {
  auto mutex = coro::mutex{};
  auto ints = std::vector<int>{};
  ints.reserve(WORK_ITEMS);

  std::println("Thread {}: passing execution to the pool",
               std::this_thread::get_id());

  co_await thread_pool.schedule();
  std::println("Thread {}: running first pooled job",
               std::this_thread::get_id());

  std::vector<coro::task<>> tasks;
  tasks.reserve(WORK_ITEMS);

  for (int i = 0; i < WORK_ITEMS; ++i) {
    tasks.emplace_back(fill_number(i, ints, thread_pool, mutex));
  }

  co_await coro::when_all(std::move(tasks));

  co_return ints;
}

int main() {
  auto thread_pool = coro::thread_pool{{.thread_count = 3}};

  std::println("Thread {}: preparing work", std::this_thread::get_id());
  auto work = do_routine_work(thread_pool);

  std::println("Thread {}: starting work", std::this_thread::get_id());
  const auto ints = coro::sync_wait(work);

  std::print("Thread {}: work done.\nProduced ints are: ",
             std::this_thread::get_id());
  for (auto i : ints) {
    std::print("{}, ", i);
  }
  std::println();
}
