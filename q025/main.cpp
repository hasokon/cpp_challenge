#include <iostream>
#include <string>

#include "capitalize.h"

int
main() {
  std::string res = cpp_challenge::capitalize("the c++ challenger");
  std::cout << res << std::endl;

  res = cpp_challenge::capitalize("tHE c++ cHALLENGER");
  std::cout << res << std::endl;
}
