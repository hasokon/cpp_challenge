#include <iostream>
#include <cstdint>
#include <cmath>
#include <cstdlib>
#include <iomanip>

long double
calc_pi_by_fourier(const uint32_t n) {
  long double pi = 0.0;
  for (auto i = 1; i <= n; ++i) {
    long double nd = static_cast<long double>(i);
    pi += 1 / (nd * nd);
  }
  return std::sqrt(pi * 6);
}

int
main (int argc, char** argv) {
  if (argc < 2) {
    return 1;
  }
  uint32_t decimal_digits = std::atoi(argv[1]);
  long double lim = std::pow(10.0, decimal_digits);

  int32_t last_pi = 0;
  long double cur_pi = 0.0;

  for (auto i = 1;; ++i) {
    cur_pi = calc_pi_by_fourier(i);
    int32_t tmp = static_cast<int32_t>(cur_pi * lim);
    std::cout << "tmp:" << tmp << std::endl;
    if ((tmp - last_pi) == 0) {
      break;
    }
    last_pi = tmp;
  }

  std::cout << std::fixed << std::setprecision(decimal_digits) << cur_pi;
  std::cout << std::endl;
  return 0;
}
