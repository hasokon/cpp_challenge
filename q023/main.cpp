#include <iostream>
#include <string>

#include "hexstring.h"

int
main () {
  std::string s1 = cpp_challenge::convert2hexstring({1,2,3,4,5});
  std::string s2 = cpp_challenge::convert2hexstring({0xBA, 0xAD, 0xFD, 0x00});

  std::cout << s1 << std::endl;
  std::cout << s2 << std::endl;
}
