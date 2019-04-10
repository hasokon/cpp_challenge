#include <iostream>
#include <cstdint>
#include <map>

uint32_t
calc_sum_of_divisor_exclude_self(const uint32_t num) {
 uint32_t sum = 0;
  for (auto i = 1; i < num; i++) {
    if (num % i == 0) {
      sum += i;
    }
  }
  return sum;
}

void
print_all_amicable_numbers(const uint32_t upper_lim) {
  std::map<uint32_t, uint32_t> divisor_map;
  uint32_t sum_of_divisor;
  uint32_t find_count = 0;
  std::cout << "search amicable numbers..." << std::endl;
  for (auto i = 1; i <= upper_lim; i++) {
    sum_of_divisor = calc_sum_of_divisor_exclude_self(i);
    if (divisor_map[sum_of_divisor] == i) {
      find_count++;
      std::cout << "Find amicable numbers pair (";
      std::cout << sum_of_divisor;
      std::cout << "," << i << ") ";
      std::cout << std::endl;
    }
    divisor_map[i] = sum_of_divisor;
  }
  std::cout << "search finish. find " << find_count << " pairs." << std::endl;
}

int
main (void) {
  uint32_t input = 0;
  while (std::cin >> input && !std::cin.eof()) {
    print_all_amicable_numbers(input);
  }
}
