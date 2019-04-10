#ifndef _STRJOIN_H_
#define _STRJOIN_H_

#include <string>
#include <algorithm>
#include <iterator>
#include <sstream>

namespace cpp_challenge {

template <class C>
std::string
strjoin(C & strs, char const * const delim) {
  std::ostringstream oss;
  std::copy(strs.cbegin(), strs.cend() - 1, std::ostream_iterator<std::string>(oss, delim));
  oss << *(strs.cend() - 1);
  return oss.str();
}

}

#endif
