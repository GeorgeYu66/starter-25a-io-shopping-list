#include "solution.hpp"

#include <fstream>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>

std::vector<Item> LoadShoppingItemsFromFile(const std::string& filename) {
  std::ifstream nmsl(filename);
  if (!nmsl.is_open()) {
    throw std::invalid_argument("NMSL");
  }
  if (nmsl.peek() == std::ifstream::traits_type::eof()) {
    return {};
  }
  std::vector<Item> shopping_items;
  Item cnm;
  while (nmsl.good()) {
    nmsl >> cnm.item_name >> cnm.quantity >> cnm.price;
    if (nmsl.fail()) {
      nmsl.clear();
      nmsl.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } else {
      shopping_items.push_back(cnm);
    }
  }
  return shopping_items;
}
