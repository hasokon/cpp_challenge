#ifndef _ARRAY2D_H_
#define _ARRAY2D_H_

#include <cstddef>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <iterator>
#include <initializer_list>

namespace cpp_challenge {

template <typename T, std::size_t N, std::size_t M>
class array2d {
private:
  std::vector<T> _data;
  typedef T* iterator;
  typedef T const *const_iterator;
public:
  constexpr array2d() : _data(N*M) {}

  array2d(const std::initializer_list<T> init) : _data() {
    if (N*M <= init.size()) {
      std::copy(init.begin(), init.begin() + N*M, std::back_inserter(_data));
      return;
    }
    std::copy(init.begin(), init.end(), std::back_inserter(_data));
    _data.resize(N*M);
  }

  constexpr array2d(array2d& other) : _data(other._data) {}

  constexpr array2d(array2d&& other) : _data(other._data) {}

  constexpr T& at(const int32_t n, const int32_t m) {
    return _data.at(n*M+m);
  }

  constexpr T const* data() const noexcept {
    return _data.data();
  }

  constexpr void fill(const T& d) noexcept {
    std::for_each(_data.begin(), _data.end(), [&d](T& x) mutable {x = d;});
  }

  constexpr size_t size_of_rows() const noexcept {
    return N;
  }

  constexpr size_t size_of_columns() const noexcept {
    return M;
  }

  constexpr void swap(array2d & other) noexcept {
    _data.swap(other._data);
  }

  constexpr iterator begin() noexcept {
    return _data.begin();
  }

  constexpr iterator end() noexcept {
    return _data.end();
  }

  constexpr const_iterator begin() const noexcept {
    return _data.begin();
  }

  constexpr const_iterator end() const noexcept {
    return _data.end();
  }
};

}

#endif
