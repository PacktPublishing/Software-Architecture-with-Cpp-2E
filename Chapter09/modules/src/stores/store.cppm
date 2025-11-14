module;

#include <vector>

export module store;

export import merchant;
export import :item;

export enum class Category {
  Food,
  Antiques,
  Books,
  Video,
  Music,
  Photography,
  Handicraft,
  Artist,
};

export struct Store {
  const Merchant *owner;
  std::vector<Item> items;
  std::vector<Category> categories;
};
