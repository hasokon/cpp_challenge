#include <vector>
#include <iostream>
#include <ios>

#include "contains.h"

int
main () {
  std::vector<int> v = {1,2,3};
  std::cout << std::boolalpha << cpp_challenge::contains_all(v, 1, 2) << std::endl;
  std::cout << std::boolalpha << cpp_challenge::contains_all(v, 1, 2, 5) << std::endl;
  std::cout << std::boolalpha << cpp_challenge::contains_any(v, 1, 5, 6) << std::endl;
  std::cout << std::boolalpha << cpp_challenge::contains_any(v, 90, 0, 4) << std::endl;
  std::cout << std::boolalpha << cpp_challenge::contains_none(v, 0, 20) << std::endl;
  std::cout << std::boolalpha << cpp_challenge::contains_none(v, 1, 20) << std::endl;
}
