#ifndef _HEXSTRING_H_
#define _HEXSTRING_H_

#include <string>
#include <cstdint>
#include <sstream>
#include <bitset>
#include <initializer_list>
#include <algorithm>
#include <iomanip>
#include <vector>

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

std::vector<uint8_t>
convert2hexvector(std::string const src) {
  std::vector<uint8_t> res(src.size() / 2);
  res.resize(0);
  uint32_t num;
  for (int i = 0; i < src.size(); i += 2) {
    num = std::stoul(src.substr(i, 2), nullptr, 16);
    res.push_back(num);
  }
  return res;
}

}

#endif
