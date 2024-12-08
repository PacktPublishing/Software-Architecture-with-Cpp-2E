#include <array>
#include <concepts>
#include <iostream>
#include <tuple>
#include <utility>
#include <variant>

class GlamorousItem {
 public:
  // void appear_in_full_glory(this auto&& self) {
  template <typename Self>
  void appear_in_full_glory(this Self&& self) {
    self.appear_in_full_glory_impl();
  }
};

class PinkHeels : public GlamorousItem {
 public:
  void appear_in_full_glory_impl() {
    std::cout << "Pink high heels suddenly appeared in all their beauty\n";
  }
};

class GoldenWatch : public GlamorousItem {
 public:
  void appear_in_full_glory_impl() {
    std::cout << "Everyone wanted to watch this watch\n";
  }
};

/*template <typename... Args>
  requires(std::derived_from<Args, GlamorousItem> && ...)*/
template <std::derived_from<GlamorousItem>... Args>
using PreciousItems = std::tuple<Args...>;

using GlamorousVariant = std::variant<PinkHeels, GoldenWatch>;

class CommonGlamorousItem {
 public:
  template <typename T>
    requires std::is_base_of_v<GlamorousItem, T>
  explicit CommonGlamorousItem(T&& item) : item_{std::forward<T>(item)} {}

  void appear_in_full_glory() {
    std::visit([]<typename T>(T& item) { item.appear_in_full_glory(); }, item_);
  }

 private:
  GlamorousVariant item_;
};

int main() {
  {
    auto glamorous_items = PreciousItems<PinkHeels, GoldenWatch>{};
    std::apply([]<std::derived_from<GlamorousItem>... T>(
                   T... items) { (items.appear_in_full_glory(), ...); },
               glamorous_items);
  }
  std::cout << "---\n";
  {
    auto glamorous_items = std::array{GlamorousVariant{PinkHeels{}},
                                      GlamorousVariant{GoldenWatch{}}};
    for (auto& elem : glamorous_items) {
      std::visit([]<std::derived_from<GlamorousItem> T>(
                     T& item) { item.appear_in_full_glory(); },
                 elem);
    }
  }
  std::cout << "---\n";
  {
    auto glamorous_items = std::array{CommonGlamorousItem{PinkHeels{}},
                                      CommonGlamorousItem{GoldenWatch{}}};
    for (auto& elem : glamorous_items) {
      elem.appear_in_full_glory();
    }
  }
}
