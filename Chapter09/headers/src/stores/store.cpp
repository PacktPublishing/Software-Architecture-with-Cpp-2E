#include "stores/store.h"

#include <iomanip>

namespace trade_fair {
std::ostream &operator<<(std::ostream &os, const Item &item) {
  auto stringify_optional = [](const auto &optional) {
    using optional_value_type =
        typename std::remove_cvref_t<decltype(optional)>::value_type;
    if constexpr (std::is_same_v<optional_value_type, std::string>) {
      return optional ? *optional : "missing";
    } else {
      return optional ? std::to_string(*optional) : "missing";
    }
  };

  os << "name: " << item.name
     << ", photo_url: " << stringify_optional(item.photo_url)
     << ", description: " << item.description << ", price: " << std::fixed
     << std::setprecision(2) << item.price.value_or(0)
     << ", date_added: " << std::format("{:%c %Z}", item.date_added)
     << ", featured: " << item.featured;
  return os;
}
} // namespace trade_fair
