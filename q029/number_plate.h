#ifndef _NUMBER_PLATE_H_
#define _NUMBER_PLATE_H_

#include <string>
#include <regex>
#include <vector>

namespace cpp_challenge {

static const std::regex regex_number_plate{ R"([A-Z]{3}-[A-Z]{2} [0-9]{3,4})" };

template <class StringT>
bool is_number_plate (StringT const & str) {
  return std::regex_match(str.cbegin(), str.cend(), regex_number_plate);
}

std::vector<std::string>
get_all_number_plate (std::string const & str) {
  std::string_view sv { str };
  std::vector numbers;
  if (str.length() < 10) {
    return numbers;
  }

  for (int i = 0; i < 
}

}

#endif
