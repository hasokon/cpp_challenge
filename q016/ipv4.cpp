#include "ipv4.h"
#include <cstdint>
#include <array>
#include <istream>
#include <ostream>

cpp_challenge::ipv4::ipv4(const ipv4 &other) noexcept : _data(other._data) {}

uint32_t
cpp_challenge::ipv4::to_uint32() const noexcept
{
  return static_cast<uint32_t>(_data[0]) << 24 |
         static_cast<uint32_t>(_data[1]) << 16 |
         static_cast<uint32_t>(_data[2]) <<  8 |
         static_cast<uint32_t>(_data[3]);
}

cpp_challenge::ipv4&
cpp_challenge::ipv4::operator=(const cpp_challenge::ipv4 & other) noexcept
{
  _data = other._data;
  return *this;
}

bool
cpp_challenge::ipv4::operator<(const ipv4& other) noexcept
{
  return to_uint32() < other.to_uint32();
}

bool
cpp_challenge::ipv4::operator<=(const ipv4& other) noexcept
{
  return to_uint32() <= other.to_uint32();
}

bool
cpp_challenge::ipv4::operator>(const ipv4& other) noexcept
{
  return to_uint32() > other.to_uint32();
}

bool
cpp_challenge::ipv4::operator>=(const ipv4& other) noexcept
{
  return to_uint32() >= other.to_uint32();
}

bool
cpp_challenge::ipv4::operator==(const ipv4& other) noexcept
{
  return _data == other._data;
}

bool
cpp_challenge::ipv4::operator!=(const ipv4& other) noexcept
{
  return !(*this == other);
}

cpp_challenge::ipv4&
cpp_challenge::ipv4::operator++(int) noexcept
{
  *this = cpp_challenge::ipv4(to_uint32() + 1);
  return *this;
}

cpp_challenge::ipv4&
cpp_challenge::ipv4::operator--(int) noexcept
{
  *this = cpp_challenge::ipv4(to_uint32() - 1);
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
