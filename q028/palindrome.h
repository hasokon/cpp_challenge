#ifndef _PALINDROME_H_
#define _PALINDROME_H_

#include <string>
#include <string_view>
#include <algorithm>

namespace cpp_challenge {

template <class StringT>
bool is_palindrome(StringT const & str) {
  return std::equal(str.cbegin(), str.cend(), str.crbegin());
}

std::string
get_longest_palindrome(std::string const & str) {
  std::string_view sv{ str };
  std::string_view longest = sv.substr(0, 1);
  std::string_view tmp;

  for (int i = 0; i < sv.length() - 1; ++i) {
    for (int len = 1; i + len <= sv.length(); ++len) {
      tmp = sv.substr(i , len);
      if (!is_palindrome(tmp)) {
        continue;
      }
      if (longest.length() >= tmp.length()) {
        continue;
      }
      longest = tmp;
    }
  }

  return std::string{ longest };
}

}

#endif
