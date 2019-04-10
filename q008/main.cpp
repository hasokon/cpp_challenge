#include <iostream>
#include <cstdint>
#include <cstdlib>

uint32_t
_pow(uint32_t x, uint32_t n, uint32_t ans) {
  if (n == 0) {
    return ans;
  }
  return _pow(x, n - 1, ans * x);
}

uint32_t
pow(uint32_t x, uint32_t n) {
  return _pow(x, n, 1);
}

int
main (int argc, char** argv) {
  uint32_t digits1, digits2, digits3;
  for (digits3 = 1; digits3 < 10; ++digits3) {
    for (digits2 = 0; digits2 < 10; ++digits2) {
      for (digits1 = 0; digits1 < 10; ++digits1) {
        auto number = digits3 * 100 + digits2 * 10 + digits1;
        auto narcissistic = pow(digits3, 3) + pow(digits2, 3) + pow(digits1, 3);
        if (number == narcissistic) {
          std::cout << number << std::endl;
        }
      }
    }
  }
}
