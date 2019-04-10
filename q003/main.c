#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <numeric>

int
main (int argc, char** argv) {
  if (argc < 3) {
    return 1;
  }

  uint32_t m = std::atoi(argv[1]);
  uint32_t n = std::atoi(argv[2]);

  std::cout << "lcm = " << std::lcm(m,n) << std::endl;
  return 0;
}
