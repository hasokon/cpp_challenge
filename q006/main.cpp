#include <iostream>
#include <cstdint>

bool
calc_abundant_number(uint32_t const num, uint32_t &abundant_number) {
  uint32_t sum = 1;
  for (auto i = 2; i < num; i++) {
    if (num % i == 0) {
      sum += i;
    }
  }
  if (sum > num) {
    abundant_number = sum + num;
    return true;
  }
  return false;
}

void
print_abundant_number(uint32_t const number) {
  uint32_t abundant_number;
  for (auto i = 1; i <= number; i++) {
    if (calc_abundant_number(i, abundant_number)) {
      std::cout << "find an abundant number " << i << " (" << abundant_number << ")" << std::endl;
    }
  }
}

int
main (void) {
  uint32_t input = 0;
  while(std::cin >> input && !std::cin.eof()) {
    std::cout << input;
    print_abundant_number(input);
  }
}
