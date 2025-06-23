#include <sw/redis++/redis++.h>

#include <algorithm>
#include <iostream>
#include <iterator>

using namespace std;
using namespace sw::redis;

int main() {
  try {
    auto redis = Redis("tcp://127.0.0.1:6379");

    redis.set("key", "val");
    if (const auto val = redis.get("key")) {
      cout << *val << endl;
    }

    redis.del("list");

    redis.rpush("list", {"a", "b", "c"});
    std::vector<std::string> vec;
    redis.lrange("list", 0, -1, std::back_inserter(vec));

    std::copy(vec.begin(), vec.end(),
              std::ostream_iterator<std::string>(std::cout, " "));
  } catch (const Error& e) {
    cerr << "Error: " << e.what() << endl;
  }

  return 0;
}
