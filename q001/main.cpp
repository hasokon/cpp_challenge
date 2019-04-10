#include <iostream>
#include <cstdlib>
#include <cstdint>
using namespace std;

int
main (int argc, char** argv) {
  if (argc < 2) {
    return 1;
  }

  uint32_t num = atoi(argv[1]);
  uint32_t sum = 0;

  for (auto i = 1; i <= num; i++) {
    if (i % 3 == 0 || i % 5 == 0) {
      cout << "sum = " << sum << "+" << i << endl;
      sum += i;
    }
  }
  cout << "result: sum = "  << sum << endl;
  return 0;
}
