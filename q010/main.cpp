#include <iostream>
#include <string>
#include <bitset>

std::string
convert_binary_string_5bit(int n) {
  std::bitset<32> bits(n);
  return bits.to_string().substr(27, 5);
}

uint32_t
decode_gray_code(uint32_t g) {
  std::bitset<32> bits(g);
  for (auto i = 3; i >= 0; --i) {
    bits[i] = bits[i] ^ bits[i+1];
  }
  return bits.to_ulong();
}

uint32_t
encode_gray_code(uint32_t n) {
  return (n ^ (n >> 1));
}

int
main() {
  for (auto i = 0; i < 32; ++i) {
    uint32_t g = encode_gray_code(i);
    uint32_t d = decode_gray_code(g);

    std::string original = convert_binary_string_5bit(i);
    std::string gray_code = convert_binary_string_5bit(g);
    std::string d_gray_code = convert_binary_string_5bit(d);

    std::cout << i << ":" << original;
    std::cout << ":" << gray_code;
    std::cout << ":" << d_gray_code;
    std::cout << std::endl;
  }
}
