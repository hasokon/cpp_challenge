#include <iostream>
#include <cstdint>
#include <cstdlib>

uint32_t
_pow(const uint32_t x, const uint32_t n, const uint32_t ans) {
  if (n == 0) {
    return ans;
  }
  return _pow(x, n - 1, ans * x);
}

uint32_t
pow(const uint32_t x, const uint32_t n) {
  return _pow(x, n, 1);
}

void
print_narcissistic_numbers(const uint32_t upper_num) {
  uint32_t digits = 1;
  uint32_t lim_digits = 10;
  uint32_t tmp;
  uint32_t sum;

  for (auto i = 0; i <= upper_num; ++i) {
    if (i >= lim_digits) {
      digits++;
      lim_digits *= 10;
    }
    tmp = i;
    sum = 0;
    for (auto j = 0; j < digits; ++j) {
      sum += pow(tmp % 10, digits);
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
