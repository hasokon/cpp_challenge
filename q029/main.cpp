#include <iostream>
#include <string>

#include "number_plate.h"

int
main () {
  std::string input;
  while (std::getline(std::cin, input)) {
    std::cout << (cpp_challenge::is_number_plate(input)) << std::endl;
  }
}
