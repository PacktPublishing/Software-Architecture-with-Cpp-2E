#include <sw/redis++/redis++.h>

#include <algorithm>
#include <iostream>
#include <iterator>

using namespace sw::redis;

int main() {
  try {
    auto redis = Redis("tcp://127.0.0.1:6379");

    redis.set("poem", "late goodbye");
    if (const auto val = redis.get("poem")) {
      std::cout << *val << std::endl;
    }

    redis.del("students");

    redis.rpush("students", {"Allison", "John", "Brian", "Andrew", "Claire"});
    std::vector<std::string> vec;
    redis.lrange("students", 0, -1, std::back_inserter(vec));

    std::copy(vec.begin(), vec.end(),
              std::ostream_iterator<std::string>(std::cout, " "));
  } catch (const Error &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  return 0;
}
