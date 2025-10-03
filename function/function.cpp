#include <string>

#include "function.hpp"

void ChangeValue(std::string &text, size_t n, const char old_value,
                 const char new_value) {
  if (n <= 0) {
    return;
  }

  size_t counter = 0;
  for (size_t i = 0; i < text.size(); ++i) {
    if (text[i] == old_value) {
      ++counter;
      if (counter == n) {
        text[i] = new_value;
        counter = 0;
      }
    }
  }
}
