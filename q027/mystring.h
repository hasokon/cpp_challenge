#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include <string>
#include <vector>
#include <cstddef>

namespace cpp_challenge {

std::vector<std::string>
split(std::string const & src, std::string const & delims) {
  std::vector<std::string> strings;
  std::size_t head = 0;
  std::size_t find = 0;
  while (head < src.length()) {
    if ((find = src.find_first_of(delims, head)) == std::string::npos) {
      strings.push_back(src.substr(head));
      break;
    }
    strings.push_back(src.substr(head, find - head));
    head = find + 1;
  }
  return strings;
}

}

#endif
