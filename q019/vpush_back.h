#ifndef _VPUSH_BACK_H_
#define _VPUSH_BACK_H_

namespace cpp_challenge {

template <class C, typename... T>
void vpush_back(C& c, T&&... args) {
  (c.push_back(args), ...);
}

}

#endif
