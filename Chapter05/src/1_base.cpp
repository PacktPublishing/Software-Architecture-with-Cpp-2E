#include <algorithm>
#include <chrono>
#include <format>
#include <gsl/pointers>
#include <iostream>
#include <optional>
#include <ostream>
#include <ranges>
#include <unordered_map>
#include <vector>

int get_current_customer_id() { return 42; }

struct Merchant {
  int id{};
};

using namespace std::chrono;
using namespace std::literals::chrono_literals;

struct Item {
  std::string name;
  std::optional<std::string> photo_url;
  std::string description;
  std::optional<float> price;
  time_point<system_clock> date_added{};
  bool featured{};
};

std::ostream &operator<<(std::ostream &os, const Item *item) {
  auto stringify_optional = []<typename T>(const T &optional) {
    using optional_value_type = typename std::remove_cvref_t<T>::value_type;
    if constexpr (std::is_same_v<optional_value_type, std::string>) {
      return optional ? *optional : "missing";
    } else {
      return optional ? std::to_string(*optional) : "missing";
    }
  };

  os << "name: " << item->name
     << ", photo_url: " << stringify_optional(item->photo_url)
     << ", description: " << item->description
     << ", price: " << stringify_optional(item->price)
     << ", date_added: " << std::format("{:%c %Z}", item->date_added)
     << ", featured: " << item->featured;
  return os;
}

enum class Category {
  Food,
  Antiques,
  Books,
  Music,
  Photography,
  Handicraft,
  Artist,
};

struct Store {
  gsl::not_null<const Merchant *> owner;
  std::vector<Item> items;
  std::vector<Category> categories;
};

using Stores = std::vector<gsl::not_null<const Store *>>;

Stores get_favorite_stores_for(int customer_id) {
  static const auto merchants = std::vector<Merchant>{{17}, {29}};
  static const auto stores = std::vector<Store>{
      {.owner = &merchants[0],
       .items =
           {
               {.name = "Honey",
                .photo_url = {},
                .description = "Straight outta Compton's apiary",
                .price = 9.99f,
                .date_added = system_clock::now(),
                .featured = false},
               {.name = "Oscypek",
                .photo_url = {},
                .description = "Tasty smoked cheese from the Tatra mountains",
                .price = 1.23f,
                .date_added = system_clock::now() - 1h,
                .featured = true},
           },
       .categories = {Category::Food}},
      {.owner = &merchants[1],
       .items = {{
           .name = "Handmade painted ceramic bowls",
           .photo_url = "http://example.com/beautiful_bowl.png",
           .description =
               "Hand-crafted and hand-decorated bowls made of fired clay",
           .price = {},
           .date_added = system_clock::now() - 12min,
           .featured = true,
       }},
       .categories = {Category::Artist, Category::Handicraft}}};
  static auto favorite_stores_by_customer =
      std::unordered_map<int, Stores>{{42, {&stores[0], &stores[1]}}};
  return favorite_stores_by_customer[customer_id];
}

using Items = std::vector<gsl::not_null<const Item *>>;

Items get_featured_items_for_store(const Store &store) {
  auto featured = Items{};
  for (const auto &items = store.items; const auto &item : items) {
    if (item.featured) {
      featured.emplace_back(&item);
    }
  }
  return featured;
}

Items get_all_featured_items(const Stores &stores) {
  auto all_featured = Items{};
  for (const auto &store : stores) {
    const auto featured_in_store = get_featured_items_for_store(*store);
    all_featured.reserve(all_featured.size() + featured_in_store.size());
    std::copy(std::begin(featured_in_store), std::end(featured_in_store),
              std::back_inserter(all_featured));
  }
  return all_featured;
}

void order_items_by_date_added(Items &items) {
  // left and right are gsl::not_null<const Item *>
  auto date_comparator = [](const auto &left, const auto &right) {
    return left->date_added > right->date_added;
  };
  std::sort(std::begin(items), std::end(items), date_comparator);
}

void render_item_gallery(const Items &items) {
  std::copy(
      std::begin(items), std::end(items),
      std::ostream_iterator<gsl::not_null<const Item *>>(std::cout, "\n"));
}

int main() {
  const auto fav_stores = get_favorite_stores_for(get_current_customer_id());

  auto selected_items = get_all_featured_items(fav_stores);

  order_items_by_date_added(selected_items);

  render_item_gallery(selected_items);
}
