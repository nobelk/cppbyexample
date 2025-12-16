#include <array>
#include <iostream>
#include <string>

/**
 * Snippets from cppbyexample.
 */

int main() {
  std::cout << "Bismillah" << std::endl;

  auto k = 9; // automatically infer types

  std::string greeting_d = "Hello";
  char greeting_b[] = "Hello";

  std::cout << k << std::endl
            << greeting_b << std::endl
            << greeting_d << std::endl;

  std::array<int, 5> myarray;

  for (size_t i = 0; i < myarray.size(); ++i) {
    myarray[i] = i;
    std::cout << myarray[i] << std::endl;
  }

  return 0;
}
