#include <co/co.h>

#include <chrono>
#include <print>
#include <random>
#include <thread>
#include <vector>

inline constexpr auto WORK_ITEMS = 5;

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> distrib(0, 800);

co::mutex g_m;

DEF_main(argc, argv) {
  std::println("Thread {} co_thread {} co_sched {}: preparing work",
               std::this_thread::get_id(), co::thread_id(), co::sched_id());
  co::wait_group wg;
  wg.add(WORK_ITEMS);

  std::vector<int> ints;

  std::println("Thread {} co_thread {} co_sched {}: starting work",
               std::this_thread::get_id(), co::thread_id(), co::sched_id());

  for (int i = 0; i < WORK_ITEMS; ++i) {
    go([wg, i, &ints]() {
      std::println(
          "Thread {} co_thread {} co_routing {} co_sched {}: producing {}",
          std::this_thread::get_id(), co::thread_id(), co::coroutine_id(),
          co::sched_id(), i);
      std::this_thread::sleep_for(std::chrono::milliseconds(distrib(gen)));

      {
        co::mutex_guard g(g_m);
        ints.emplace_back(i);
      }

      std::println(
          "Thread {} co_thread {} co_routing {} co_sched {}: produced {}",
          std::this_thread::get_id(), co::thread_id(), co::coroutine_id(),
          co::sched_id(), i);
      wg.done();
    });
  }

  wg.wait();

  std::print(
      "Thread {} co_thread {} co_sched {}: work done.\nProduced ints are: ",
      std::this_thread::get_id(), co::thread_id(), co::sched_id());
  for (auto i : ints) {
    std::print("{}, ", i);
  }
  std::println();

  return 0;
}
