#include <drogon/drogon.h>

using namespace drogon;

int main() {
  app().addListener("0.0.0.0", 8080).setThreadNum(0).run();

  return 0;
}
