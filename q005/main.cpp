#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <vector>

using namespace std;

bool
is_prime(uint32_t num) {
  if (num < 2) {
    return false;
  }
  if (num == 2) {
    return true;
  }
  if (num % 2 == 0) {
    return false;
  }

  for (auto i = 3; i < num/2; i+=2) {
    if (num % i == 0) {
      return false;
    }
  }

  return true;
}

int
main (int argc, char** argv) {
  if (argc < 2) {
    return 1;
  }

  uint32_t num = atoi(argv[1]);
  
  for (auto i = 11; i <= num; i++) {
    if (is_prime(i)) {
      if (is_prime(i-6)) {
        cout << (i-6) << "," << i << endl;
      }
    }
  }

  return 0;
}
