#include "vpush_back.h"

#include <iostream>
#include <vector>
#include <algorithm>

int
main () {
  std::vector<int> v;
  cpp_challenge::vpush_back(v, 1,2,3,4,4,5,6,9);
  std::for_each(v.begin(), v.end(), [](int x) {std::cout << x << std::endl;});
}
