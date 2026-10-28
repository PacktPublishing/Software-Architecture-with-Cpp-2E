#include <algorithm>
#include <chrono>
#include <iostream>
#include <optional>
#include <ranges>
#include <unordered_map>
#include <vector>

// #include "stores/customer.h"
import customer;
// import merchant; // not necessary -- exported by store
import store;

using namespace std::chrono;
using namespace std::literals::chrono_literals;
using namespace std::ranges;

using namespace trade_fair;

using Stores = std::vector<const Store *>;

Stores get_favorite_stores_for(const CustomerId &customer_id) {
  static const auto merchants = std::vector<Merchant>{{17}, {29}};
  static const auto stores = std::vector<Store>{
      {.owner = &merchants[0],
       .items =
           {
               {.name = "MicroWasp",
                .photo_url = {},
                .description = "A mechanical skateboard keyboard",
                .price = 575.0f,
                .date_added = system_clock::now(),
                .featured = false},
               {.name = "Power glove",
                .photo_url = {},
                .description = "The hacker secret tool",
                .price = 122.50f,
                .date_added = system_clock::now() - 1h,
                .featured = true},
           },
       .categories = {Category::Handicraft}},
      {.owner = &merchants[1],
       .items =
           {
               {
                   .name = "The wizard",
                   .photo_url = "http://example.com/vhs.png",
                   .description =
                       "A family film about a boy with a natural talent for "
                       "video games",
                   .price = {},
                   .date_added = system_clock::now() - 12min,
                   .featured = true,
               },
               {
                   .name = "Tsuki Kage Mai Ka - Wagakki Band",
                   .photo_url = "http://example.com/jrock_song.png",
                   .description = "A high-energy blend of traditional Japanese "
                                  "instruments like the koto and shamisen with "
                                  "modern rock",
                   .price = {},
                   .date_added = system_clock::now() - 12min,
                   .featured = true,
               },
               {
                   .name = "Goodbye to You - Scandal",
                   .photo_url = "http://example.com/rock_song.png",
                   .description = "An energetic breakup anthem about cutting "
                                  "ties with a bad ex",
                   .price = {},
                   .date_added = system_clock::now() - 12min,
                   .featured = true,
               },
               {
                   .name = "You Don't Know - Berlin",
                   .photo_url = "http://example.com/new_wave_song.png",
                   .description = "A bittersweet suffering in silence while "
                                  "loving someone who doesn't even notice",
                   .price = {},
                   .date_added = system_clock::now() - 12min,
                   .featured = true,
               },
               {
                   .name = "8.15 To Nowhere - Vicious Pink",
                   .photo_url = "http://example.com/new_wave_song.png",
                   .description = "Getting lost in the pulsing rhythm of a "
                                  "never-ending train ride",
                   .price = {},
                   .date_added = system_clock::now() - 12min,
                   .featured = true,
               },
               {
                   .name = "Angel Of The Morning - Juice Newton",
                   .photo_url = "http://example.com/folk_rock_song.png",
                   .description = "Embracing a temporary romance with zero "
                                  "regrets and no matter what tomorrow brings",
                   .price = {},
                   .date_added = system_clock::now() - 12min,
                   .featured = true,
               },
           },
       .categories = {Category::Artist, Category::Video, Category::Music}}};
  static auto favorite_stores_by_customer =
      std::unordered_map<CustomerId, Stores>{{42, {&stores[0], &stores[1]}}};
  return favorite_stores_by_customer[customer_id];
}

using Items = std::vector<const Item *>;

auto get_featured_items_for_store(const Store &store) {
  return store.items | views::filter(&Item::featured) |
         views::transform([](const auto &item) { return &item; });
}

auto get_all_featured_items(const Stores &stores) -> Items {
  auto all_featured = stores | views::transform([](auto elem) {
                        return get_featured_items_for_store(*elem);
                      }) |
                      views::join;
  auto as_items = Items{};
  as_items.reserve(distance(all_featured));
  copy(all_featured, std::back_inserter(as_items));
  return as_items;
}

template <typename Range, typename Comp, typename Proj>
concept sortable_range =
    random_access_range<Range> && std::sortable<iterator_t<Range>, Comp, Proj>;

void order_items_by_date_added(
    sortable_range<greater, decltype(&Item::date_added)> auto &items) {
  sort(items, greater{}, &Item::date_added);
}

template <input_range Container>
  requires std::is_same_v<typename Container::value_type, const Item *>
void render_item_gallery(const Container &items) {
  auto printable_items =
      items |
      views::transform(
          [](auto *item) -> std::add_lvalue_reference_t<decltype(*item)> {
            return *item;
          });
  copy(printable_items, std::ostream_iterator<Item>(std::cout, "\n"));
}

int main() {
  auto fav_stores = get_favorite_stores_for(get_current_customer_id());

  auto selected_items = get_all_featured_items(fav_stores);

  order_items_by_date_added(selected_items);

  render_item_gallery(selected_items);
}
