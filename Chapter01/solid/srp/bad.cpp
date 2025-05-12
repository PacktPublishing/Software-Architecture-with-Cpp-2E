#include <string>
#include <vector>

class FileManagerAndParser {
 public:
  int read(char* s, std::streamsize n) { return 0; }

  void write(const char* s, std::streamsize n) {}

  std::vector<int> parse(const std::string& s);
};
