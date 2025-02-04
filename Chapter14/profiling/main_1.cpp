#include <cassert>
#include <string>
#include <tracy/Tracy.hpp>
#include <unordered_map>

using namespace std;

const unordered_map<string, string> morse_code{
    {".-", "A"},      {"-...", "B"},   {"-.-.", "C"},       {"-..", "D"},
    {".", "E"},       {"..-.", "F"},   {"--.", "G"},        {"....", "H"},
    {"..", "I"},      {".---", "J"},   {"-.-", "K"},        {".-..", "L"},
    {"--", "M"},      {"-.", "N"},     {"---", "O"},        {".--.", "P"},
    {"--.-", "Q"},    {".-.", "R"},    {"...", "S"},        {"-", "T"},
    {"..-", "U"},     {"...-", "V"},   {".--", "W"},        {"-..-", "X"},
    {"-.--", "Y"},    {"--..", "Z"},   {"-----", "0"},      {".----", "1"},
    {"..---", "2"},   {"...--", "3"},  {"....-", "4"},      {".....", "5"},
    {"-....", "6"},   {"--...", "7"},  {"---..", "8"},      {"----.", "9"},
    {".-.-.-", "."},  {"--..--", ","}, {"..--..", "?"},     {".----.", "'"},
    {"-.-.--", "!"},  {"-..-.", "/"},  {"-.--.", "("},      {"-.--.-", ")"},
    {".-...", "&"},   {"---...", ":"}, {"-.-.-.", ";"},     {"-...-", "="},
    {".-.-.", "+"},   {"-....-", "-"}, {"..--.-", "_"},     {".-..-.", "\""},
    {"...-..-", "$"}, {".--.-.", "@"}, {"...---...", "SOS"}};

std::string decode_morse(const std::string &morse_msg) {
  std::string decoded, seq;
  bool is_space{false};

  ZoneScoped;
  for (const auto c : morse_msg) {
    ZoneScopedN("decode-loop");
    if (c == '.' || c == '-') {
      ZoneScopedN("dot-dash");
      if (is_space && !decoded.empty()) decoded += ' ';
      seq += c;
      is_space = false;
    } else if (c == ' ') {
      ZoneScopedN("space");
      if (!seq.empty()) {
        decoded += morse_code.at(seq);
        seq.clear();
      } else {
        is_space = true;
      }
    }
  }

  if (!seq.empty()) {
    decoded += morse_code.at(seq);
  }

  return decoded;
}

int main() {
  ZoneScoped;
  assert(decode_morse("-.-- --- -....- .-- .- -.-- -....- -.-- ---") ==
         "YO-WAY-YO");

  return 0;
}
