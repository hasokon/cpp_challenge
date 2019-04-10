#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <string>

static const std::string roman_nums[][3] = {
  {"I", "V", "X"},
  {"X", "L", "C"},
  {"C", "D", "M"},
  {"M", "", ""}
};

std::string
_print_roman(const uint32_t number, const uint32_t digits) {
  std::string roman = "";
  if (number == 0) {
    return roman;
  }
  if (number < 4) {
    for (auto i = 0; i < number; ++i) {
      roman.append(roman_nums[digits-1][0]);
    }
    return roman;
  }
  if (number == 4) {
    roman.append(roman_nums[digits-1][0]);
    roman.append(roman_nums[digits-1][1]);
    return roman;
  }
  if (number < 9) {
    roman.append(roman_nums[digits-1][1]);
    for (auto i = 5; i < number; ++i) {
      roman.append(roman_nums[digits-1][0]);
    }
    return roman;
  }
  roman.append(roman_nums[digits-1][0]);
  roman.append(roman_nums[digits-1][2]);
  return roman;
}

void
print_roman(uint32_t number) {
  if (number >= 4000) {
    std::cout << "Invalid Number: the number greater than or equal 4000 can not be printed";
    std::cout << std::endl;
    return;
  }
  std::cout << _print_roman(number / 1000, 4);
  number %= 1000;
  std::cout << _print_roman(number / 100, 3);
  number %= 100;
  std::cout << _print_roman(number / 10, 2);
  number %= 10;
  std::cout << _print_roman(number, 1);
  std::cout << std::endl;
}

int
main (int argc, char** argv) {
  if (argc < 2) {
    return 1;
  }

  uint32_t input = std::atoi(argv[1]);
  print_roman(input);
}
