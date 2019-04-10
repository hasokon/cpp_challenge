#ifndef _CAPITALIZE_H_
#define _CAPITALIZE_H_

#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <istream>
#include <algorithm>

namespace cpp_challenge {

std::string
capitalize(std::string const && str) {
  std::stringstream ss{str};
  std::vector<std::string> strings;
  std::string buf;
  while (std::getline(ss, buf, ' ')) {
    std::transform(buf.begin(), buf.begin() + 1, buf.begin(), ::toupper);
    std::transform(buf.begin() + 1, buf.end(), buf.begin() + 1, ::tolower);
    strings.push_back(buf);
  }

  std::ostringstream oss;
  std::copy(strings.cbegin(), strings.cend(), std::ostream_iterator<std::string>(oss, " "));
  return oss.str();
}

}

#endif
