#include <iostream>

#include "func.hpp"

int main() {
  std::string text;
  size_t n;
  char old_value, new_value;
  std::cout << "Номер целевой буквы, целевой символ, "
               "символ, который следует использовать в качестве замены, и "
               "исходную строку: ";
  std::cin >> n;
  std::cin >> old_value;
  std::cin >> new_value;
  std::getline(std::cin >> std::ws, text);
  ChangeValue(text, n, old_value, new_value);
  std::cout << text << '\n';
}
