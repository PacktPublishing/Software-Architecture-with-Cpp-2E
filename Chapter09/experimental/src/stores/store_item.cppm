export module store:item;

import std;

using namespace std::chrono;

export struct Item {
  std::string name;
  std::optional<std::string> photo_url;
  std::string description;
  std::optional<float> price;
  time_point<system_clock> date_added{};
  bool featured{};
};

export std::ostream &operator<<(std::ostream &os, const Item &item) {
  auto stringify_optional = []<typename T>(const T &optional) {
    using optional_value_type = typename std::remove_cvref_t<T>::value_type;
    if constexpr (std::is_same_v<optional_value_type, std::string>) {
      return optional ? *optional : "missing";
    } else {
      return optional ? std::to_string(*optional) : "missing";
    }
  };

  os << "name: " << item.name
     << ", photo_url: " << stringify_optional(item.photo_url)
     << ", description: " << item.description
     << ", price: " << std::setprecision(2) << stringify_optional(item.price)
     << ", date_added: " << std::format("{:%c %Z}", item.date_added)
     << ", featured: " << item.featured;
  return os;
}
