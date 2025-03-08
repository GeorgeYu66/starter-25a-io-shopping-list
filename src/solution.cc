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
  while (nmsl.good()) {
    Item cnm;
    nmsl >> cnm.item_name >> cnm.quantity >> cnm.price;
    if (nmsl.fail()) {
      throw std::invalid_argument("NMSL");
    }
    shopping_items.push_back(cnm);
  }
  if (shopping_items.empty()) {
    throw std::invalid_argument("NMSL");
  }
  return shopping_items;
}
