#include <iostream>

#include "ipv4.h"

int
main () {
  auto addr = cpp_challenge::ipv4();
  std::cin >> addr;
  while (!std::cin.fail()) {
    std::cout << addr << std::endl;
    std::cin >> addr;
  }
}
