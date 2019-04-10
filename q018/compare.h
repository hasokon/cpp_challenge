#ifndef _COMPARE_H_
#define _COMPARE_H_

namespace cpp_challenge {

template <typename T>
T min (T const & a, T const & b) {
  return a < b ? a : b;
}

template <typename T1, typename... T2>
T1 min (T1 head, T2... rest) {
  return min(head, min(rest...));
}

template <class Compare, typename T>
T compare (Compare comp, T const & a, T const & b) {
  return comp(a,b) ? a : b;
}

template <class Compare, typename T1, typename... T2>
T1 compare (Compare comp, T1 head, T2... rest) {
  return compare (comp, head, compare(comp, rest...));
}

}

#endif
