#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>

#include "mystring.h"

int
main () {
  std::string src = "The C++ Challenge";
  std::string delims = ";:, ";

  auto result = cpp_challenge::split(src, delims);

  std::cout << "{\"";
  std::copy(result.cbegin(), result.cend() - 1, std::ostream_iterator<std::string>(std::cout, "\",\""));
  std::cout << *(result.cend() - 1) << "\"}" << std::endl;
}
