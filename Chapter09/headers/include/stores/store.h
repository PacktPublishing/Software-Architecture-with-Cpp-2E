#pragma once

#include <chrono>
#include <optional>
#include <string>
#include <vector>

#include "stores/merchant.h"

using namespace std::chrono;

struct Item {
  std::string name;
  std::optional<std::string> photo_url;
  std::string description;
  std::optional<float> price;
  time_point<system_clock> date_added{};
  bool featured{};
};

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
  const Merchant *owner;
  std::vector<Item> items;
  std::vector<Category> categories;
};

std::ostream &operator<<(std::ostream &os, const Item &item);
