#ifndef _HEXSTRING_H_
#define _HEXSTRING_H_

#include <string>
#include <cstdint>
#include <sstream>
#include <bitset>
#include <initializer_list>
#include <algorithm>
#include <iomanip>

namespace cpp_challenge {

std::string const
convert2hexstring(std::initializer_list<uint8_t> const & list) {
  std::stringstream ss;
  ss << std::hex;
  ss.fill('0');
  std::for_each(list.begin(), list.end(), [&ss](uint8_t x) mutable {
    ss << std::setw(2) << static_cast<uint32_t>(x);
  });
  return ss.str();
}

}

#endif
