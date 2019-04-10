#include <iostream>

#include "temperature.h"

using namespace cpp_challenge::temperature_literals;

int
main () {
  cpp_challenge::kelvin k = 300.0_k;
  cpp_challenge::degree_celsius deg = k;
  cpp_challenge::degree_fahrenheit f = k;

  std::cout << "k: " << k << std::endl;
  std::cout << "c: " << deg << std::endl;
  std::cout << "f: " << f << std::endl;
  std::cout << "deg + k: " << (deg + k) << std::endl;
  std::cout << "f + k: " << (f + k) << std::endl;
  std::cout << "f + 20.0: " << (f + 20.0) << std::endl;
  std::cout << "25.6_deg + 12.3_deg: " << (25.6_deg + 12.3_deg) << std::endl;
}
