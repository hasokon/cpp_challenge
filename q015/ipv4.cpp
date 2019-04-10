#include "ipv4.h"
#include <cstdint>
#include <array>
#include <istream>
#include <ostream>

cpp_challenge::ipv4::ipv4(const ipv4 &other) noexcept : _data(other._data) {}

cpp_challenge::ipv4&
cpp_challenge::ipv4::operator=(const cpp_challenge::ipv4 & other) noexcept
{
  _data = other._data;
  return *this;
}

const std::array<uint8_t, 4>&
cpp_challenge::ipv4::get_data() const noexcept 
{
  return _data;
}

std::istream&
cpp_challenge::operator>>(std::istream& is, cpp_challenge::ipv4& a)
{
  uint32_t a1, a2, a3, a4;
  char d1, d2, d3;
  is >> a1 >> d1 >> a2 >> d2 >> a3 >> d3 >> a4;
  if (d1 == '.' && d2 == '.' && d3 == '.') {
    a = cpp_challenge::ipv4(a1, a2, a3, a4);
  } else {
    is.setstate(std::ios_base::failbit);
  }
  return is;
}

std::ostream&
cpp_challenge::operator<<(std::ostream& os, const cpp_challenge::ipv4& a)
{
  os << static_cast<uint32_t>(a._data[0]) << ".";
  os << static_cast<uint32_t>(a._data[1]) << ".";
  os << static_cast<uint32_t>(a._data[2]) << ".";
  os << static_cast<uint32_t>(a._data[3]);
  return os;
}
