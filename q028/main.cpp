#include <iostream>
#include <string>

#include "palindrome.h"

int
main () {
  std::string input;
  while (std::getline(std::cin, input)) {
    std::cout << (cpp_challenge::get_longest_palindrome(input)) << std::endl;
  }
}
