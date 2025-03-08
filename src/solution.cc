#include "solution.hpp"

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

std::vector<Item> LoadShoppingItemsFromFile(const std::string& filename) {
  std::ifstream nmsl(filename);
  if (!nmsl.is_open()) {
    throw std::invalid_argument("NMSL");
  }
  std::vector<Item> shopping_items;
  Item cnm;
  while (nmsl.good()) {
    std::cin >> cnm.item_name >> cnm.quantity >> cnm.price;
    shopping_items.push_back(cnm);
    if (nmsl.fail()) {
      throw std::invalid_argument("NMSL");
    }
  }
  if (shopping_items.empty()) {
    throw std::invalid_argument("NMSL");
  }
  return shopping_items;
}