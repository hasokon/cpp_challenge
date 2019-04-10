#include <iostream>
#include <cstdio>

#include "uniq_descriptor.h"

int
main () {
  cpp_challenge::unix_invalid_descriptor uid {
    std::fopen("text", "r")
  };

  if (!uid) {
    std::cerr << "fail: open text file" << std::endl;
    return 1;
  }

  int c;
  while ((c = std::fgetc(uid.get())) != EOF) {
    std::putc(c, stdout);
  }
  std::putc('\n', stdout);
}
