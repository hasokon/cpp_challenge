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
  constexpr ipv4(const uint32_t src) :
    ipv4( static_cast<uint8_t>(src >> 24),
          static_cast<uint8_t>((src >> 16) & 0x000000ff),
          static_cast<uint8_t>((src >> 8) & 0x000000ff),
          static_cast<uint8_t>(src & 0x000000ff)) {}
  ipv4(const ipv4 &other) noexcept;
  uint32_t to_uint32() const noexcept;
  ipv4& operator=(const ipv4& other) noexcept;
  bool operator<(const ipv4& other) noexcept;
  bool operator<=(const ipv4& other) noexcept;
  bool operator>(const ipv4& other) noexcept;
  bool operator>=(const ipv4& other) noexcept;
  bool operator==(const ipv4& other) noexcept;
  bool operator!=(const ipv4& other) noexcept;
  ipv4& operator++(int) noexcept;
  ipv4& operator--(int) noexcept;
  const std::array<uint8_t, 4>& get_data() const noexcept;
  friend std::istream& operator>>(std::istream &is, ipv4 &a);
  friend std::ostream& operator<<(std::ostream &os, const ipv4 &a);
};

std::istream& operator>>(std::istream &is, ipv4 &a);
std::ostream& operator<<(std::ostream &os, const ipv4 &a);

}

#endif
