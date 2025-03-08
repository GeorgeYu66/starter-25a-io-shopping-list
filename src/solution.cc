#include "solution.hpp"

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

std::vector<Item> LoadShoppingItemsFromFile(const std::string& filename) {
  std::ifstream nmsl(filename);
  std::vector<Item> shopping_items;
  Item cnm;
  while (nmsl.good()) {
    std::cin >> cnm.item_name >> cnm.quantity >> cnm.price;
    shopping_items.push_back(cnm);
  }
  return shopping_items;
}