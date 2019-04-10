#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <string>

bool
is_digit(const std::string str) {
  try {
    std::stoi(str);
  } catch (...) {
    return false;
  }
  return true;
}

bool
is_isbn_number(const std::string str) {
  if (str.length() != 10) {
    return false;
  }
  if (!is_digit(str.substr(0,9))) {
    return false;
  }

  uint32_t sum = 0;
  for (int i=10; i > 1; --i) {
    sum += std::stoi(str.substr(10-i,1))*i;
  }
  uint32_t check_digit = 11 - (sum % 11);
  if (check_digit < 10) {
    try {
      uint32_t input_check_digit = std::stoi(str.substr(9,1));
      return input_check_digit == check_digit;
    } catch (...) {
      return false;
    }
  }

  return str[9] == 'X';
}

int
main () {
  std::string input;
  while (std::getline(std::cin, input)) {
    std::cout << "This is " << (is_isbn_number(input) ? "ISBN" : "not ISBN")<< std::endl;
  }
}
