#include <iostream>
#include <cstdint>
#include <vector>
#include <cstdlib>
#include <iterator>

#define UPPER_LIMIT 1000000

std::vector<uint32_t>*
calc_collatz_numbers(const uint32_t n) {
  uint32_t num = n;
  auto *collatz_numbers = new std::vector<uint32_t>();
  uint32_t surpls;

  while (num != 1) {
    collatz_numbers->push_back(num);
    surpls = num % 2;
    switch (surpls) {
    case 0:
      num = num / 2;
      break;
    case 1:
      num = num * 3 + 1;
      break;
    }
  }
  return collatz_numbers;
}

int main(int argc, char** argv) {
  std::vector<uint32_t> *ans;
  uint32_t max_length = 0;
  for (auto i = 1; i < UPPER_LIMIT; ++i) {
    std::vector<uint32_t> *tmp = calc_collatz_numbers(i);
    if (tmp->size() > max_length) {
      max_length = tmp->size();
      ans = tmp;
    }
  }
  std::cout << "answer: " << ans->at(0) << std::endl;
  std::copy(ans->begin(), ans->end(), std::ostream_iterator<uint32_t>(std::cout, "->"));
  std::cout << "1" << std::endl;
}
