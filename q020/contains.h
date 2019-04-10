#ifndef _CONTAINS_H_
#define _CONTAINS_H_

#include <algorithm>

namespace cpp_challenge {

template <class C, typename T>
bool contains(C const & c, T const & arg) {
  return std::find(c.cbegin(), c.cend(), arg) != c.cend();
}

template <class C, typename... T>
bool contains_all(C& c, T&& ...args) {
  return (contains(c, args) && ...);
}

template <class C, typename... T>
bool contains_any(C& c, T&& ...args) {
  return (contains(c, args) || ...);
}

template <class C, typename... T>
bool contains_none(C& c, T&& ...args) {
  return !(contains(c, args) || ...);
}

}

#endif
