#include <iostream>
#include <cstdint>
#include <vector>
#include <cstdlib>
#include <iterator>

void
factor(const uint32_t num, std::vector<uint32_t> &factors) {
  uint32_t num_t = num;
  for (auto i = 2; i <= num_t;) {
    if (num_t == 1) {
      break;
    }
    if (num_t % i == 0) {
      factors.push_back(i);
      num_t /= i;
      continue;
    }
    ++i;
  }
}

int
main(int argc, char** argv) {
  if (argc < 2) {
    return 1;
  }

  uint32_t input = std::atoi(argv[1]);
  std::vector<uint32_t> ans;
  factor(input, ans);
  std::cout << input << ": ";
  std::copy(ans.begin(), ans.end(), std::ostream_iterator<uint32_t>(std::cout, " "));
  std::cout << std::endl;
}
