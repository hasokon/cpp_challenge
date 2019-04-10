#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <algorithm>
#include <bitset>

#include "hexstring.h"

int
main () {
  std::vector<uint8_t> res = cpp_challenge::convert2hexvector("BAADF00D");

  std::cout << "{ ";
  std::for_each(res.begin(), res.end(), [](uint8_t x) {
    std::cout << std::hex << static_cast<uint32_t>(x) << " ";
  });
  std::cout << "}" << std::endl;
}
