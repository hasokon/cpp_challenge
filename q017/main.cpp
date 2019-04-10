#include <iostream>
#include <cstdint>

#include "array2d.h"

void
print_array2d(cpp_challenge::array2d<int32_t, 2, 3>& a) {
  std::cout << "Array 2D --------" << std::endl;
  std::cout << "rows    : " << a.size_of_rows() << std::endl;
  std::cout << "columns : " << a.size_of_columns() << std::endl;
  for (int i = 0; i < a.size_of_rows(); ++i) {
    for (int j = 0; j < a.size_of_columns(); ++j) {
      std::cout << a.at(i, j) << " ";
    }
    std::cout << std::endl;
  }
}

int
main () {
  cpp_challenge::array2d<int32_t, 2, 3> a2d = {1, 2, 3, 4, 5, 6, 7};
  print_array2d(a2d);
  a2d.fill(23);
  print_array2d(a2d);

  cpp_challenge::array2d<int32_t, 2, 3> a2d2 = {9, 8, 7, 6, 5, 4};
  a2d2.swap(a2d);
  print_array2d(a2d);
  print_array2d(a2d2);
}
