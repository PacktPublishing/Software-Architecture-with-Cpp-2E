#include <string>
#include <vector>

class FileManager {
 public:
  int read(char* s, std::streamsize n) { return 0; }

  void write(const char* s, std::streamsize n) {}
};

class Parser {
 public:
  std::vector<int> parse(const std::string& s);
};
