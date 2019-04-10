#ifndef _IPV4_H_
#define _IPV4_H_
#include <cstdint>
#include <array>
#include <istream>
#include <ostream>

namespace cpp_challenge {

class ipv4
{
private:
  std::array<uint8_t, 4> _data;

public:
  constexpr ipv4(const uint8_t a, const uint8_t b, const uint8_t c, const uint8_t d) : _data({a, b, c, d}) {}
  constexpr ipv4() : ipv4(0, 0, 0, 0) {}
  ipv4(const ipv4 &other) noexcept;
  ipv4& operator=(const ipv4 & other) noexcept;
  const std::array<uint8_t, 4>& get_data() const noexcept;
  friend std::istream& operator>>(std::istream &is, ipv4 &a);
  friend std::ostream& operator<<(std::ostream &os, const ipv4 &a);
};

std::istream& operator>>(std::istream &is, ipv4 &a);
std::ostream& operator<<(std::ostream &os, const ipv4 &a);

}

#endif
