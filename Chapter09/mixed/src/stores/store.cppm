module;

#include <vector>

export module store;

export import merchant;
export import :item;

export namespace trade_fair {
enum class Category {
  Food,
  Antiques,
  Books,
  Video,
  Music,
  Photography,
  Handicraft,
  Artist,
};

struct Store {
  const Merchant *owner;
  std::vector<Item> items;
  std::vector<Category> categories;
};
} // namespace trade_fair
