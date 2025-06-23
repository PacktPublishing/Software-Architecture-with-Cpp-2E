#include <functional>
#include <iostream>
#include <ranges>

#if !defined(_MSC_VER)
#include <generator>
#else
#include <experimental/generator>
#endif

struct Node {
  int value{};
  Node *left{nullptr}, *right{nullptr};
};

#if !defined(_MSC_VER)
std::generator<const Node *> in_order(const Node *node) {
#else
std::experimental::generator<const Node *> in_order(const Node *node) {
#endif
  namespace ranges = std::ranges;

  if (node == nullptr)
    co_return;

  if (node->left != nullptr)
    co_yield ranges::elements_of(in_order(node->left));
  co_yield node;
  if (node->right != nullptr)
    co_yield ranges::elements_of(in_order(node->right));
}

#if !defined(_MSC_VER)
std::generator<const Node *> pre_order(const Node *node) {
#else
std::experimental::generator<const Node *> pre_order(const Node *node) {
#endif
  namespace ranges = std::ranges;

  if (node == nullptr)
    co_return;

  co_yield node;
  if (node->left != nullptr)
    co_yield ranges::elements_of(pre_order(node->left));
  if (node->right != nullptr)
    co_yield ranges::elements_of(pre_order(node->right));
}

#if !defined(_MSC_VER)
std::generator<const Node *> post_order(const Node *node) {
#else
std::experimental::generator<const Node *> post_order(const Node *node) {
#endif
  namespace ranges = std::ranges;

  if (node == nullptr)
    co_return;

  if (node->left != nullptr)
    co_yield ranges::elements_of(post_order(node->left));
  if (node->right != nullptr)
    co_yield ranges::elements_of(post_order(node->right));
  co_yield node;
}

#if !defined(_MSC_VER)
void print_tree(
    const Node *node,
    const std::function<std::generator<const Node *>(const Node *node)> &walk) {
#else
void print_tree(const Node *node,
                const std::function<std::experimental::generator<const Node *>(
                    const Node *node)> &walk) {
#endif
  for (const auto *n : walk(node)) {
    std::cout << n->value << ' ';
  }
  std::cout << std::endl;
}

int main() {
  Node n7{7};
  Node n6{6};
  Node n5{5};
  Node n4{4};
  Node n3{.value = 3, .left = &n6, .right = &n7};
  Node n2{.value = 2, .left = &n4, .right = &n5};
  Node n1{.value = 1, .left = &n2, .right = &n3};

  print_tree(&n1, in_order);   // 4 2 5 1 6 3 7
  print_tree(&n1, pre_order);  // 1 2 4 5 3 6 7
  print_tree(&n1, post_order); // 4 5 2 6 7 3 1
}
