#include <iostream>
#include <cstdint>
#include <cstdlib>

void
print_narcissistic_numbers(const uint32_t upper_num) {
  uint32_t num_pow[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  uint32_t digits = 1;
  uint32_t lim_digits = 10;
  uint32_t tmp;
  uint32_t sum;
  uint32_t i,j;

  for (i = 0; i <= upper_num; ++i) {
    if (i >= lim_digits) {
      digits++;
      lim_digits *= 10;
      for (j = 1; j < 10; ++j) {
        num_pow[j] *= j;
      }
    }
    tmp = i;
    sum = 0;
    for (j = 0; j < digits; ++j) {
      sum += num_pow[tmp % 10];
      tmp /= 10;
    }
    if (sum == i) {
      std::cout << sum << std::endl;
    }
  }
}

int
main (int argc, char** argv) {
  if (argc < 2) {
    return 1;
  }
  uint32_t num = std::atoi(argv[1]);
  print_narcissistic_numbers(num);
}
