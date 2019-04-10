#include <iostream>

#include "compare.h"

int
main () {
  const int min = cpp_challenge::min(1, 3, 10, 11, 1029, -2);
  std::cout << min << std::endl;

  const int max = cpp_challenge::compare([](int a, int b) { return a > b;}, 1, 12, 200, -1, 2012) ;
  std::cout << max << std::endl;
}
