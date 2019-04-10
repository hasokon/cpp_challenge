#include <iostream>
#include <sstream>
#include <string>

#include "ipv4.h"

int
main (int argc, char** argv) {
  if (argc < 2) {
    std::cerr << "Usage: command <ip addr from> <ip addr to>" << std::endl;
    return 1;
  }

  cpp_challenge::ipv4 addr_from;
  cpp_challenge::ipv4 addr_to;

  std::stringstream ss;

  ss << argv[1];
  ss >> addr_from;

  ss.clear(std::stringstream::goodbit);

  ss << argv[2];
  ss >> addr_to;

  for (cpp_challenge::ipv4 addr = addr_from; addr <= addr_to; addr++) {
    std::cout << addr << std::endl;
  }
}
