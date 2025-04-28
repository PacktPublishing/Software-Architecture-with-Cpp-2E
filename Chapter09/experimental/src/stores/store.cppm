export module store;

import std;

export import merchant;
export import :item;

export enum class Category {
  Food,
  Antiques,
  Books,
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
