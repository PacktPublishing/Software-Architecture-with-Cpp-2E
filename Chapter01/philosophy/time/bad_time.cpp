struct Duration {
  int millis_;
};

void example() {
  auto d = Duration{};
  d.millis_ = 100;

  auto timeout = 1;    // one second
  d.millis_ = timeout; // error: we meant 1000 milliseconds but assigned just 1
}
