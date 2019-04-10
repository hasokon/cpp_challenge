#include <iostream>
#include <vector>
#include <string>

#include "strjoin.h"

int
main () {
  std::vector strs = {"This", "is", "C++", "Challenge"};
  std::string str = cpp_challenge::strjoin(strs, " ");
  std::cout << str << std::endl;
}
