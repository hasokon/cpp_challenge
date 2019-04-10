#ifndef _UNIQ_DESCRIPTOR_H_
#define _UNIQ_DESCRIPTOR_H_

#include <iostream>
#include <cstdio>
#include <utility>

namespace cpp_challenge {

template <typename Traits>
class uniq_descriptor {
private:
  using pointer = typename Traits::pointer;
  pointer m_value;
public:
  explicit uniq_descriptor(pointer src = Traits::invalid()) noexcept : m_value{src} {}
  uniq_descriptor(uniq_descriptor const & other) = delete;
  uniq_descriptor& operator=(uniq_descriptor const & other) = delete;

  constexpr uniq_descriptor(uniq_descriptor&& other) noexcept : m_value{other.release()} {}

  uniq_descriptor& operator=(uniq_descriptor && other) noexcept {
    if (m_value != other.m_value) {
      reset(other.release());
    }
    return *this;
  }

  ~uniq_descriptor() noexcept {
    std::cerr << "destroied descriptor" << std::endl;
    Traits::close(m_value);
  }

  pointer release() noexcept {
    auto tmp = m_value;
    m_value = Traits::invalid();
    return tmp;
  }

  explicit operator bool() const noexcept {
    return m_value != Traits::invalid();
  }

  pointer get() const noexcept {
    return m_value;
  }

  bool reset(pointer p = Traits::invalid()) noexcept {
    if (m_value != p) {
      Traits::close(m_value);
      m_value = p;
    }
    return static_cast<bool>(*this);
  }

  void swap(uniq_descriptor<Traits> & other) noexcept {
    std::swap(m_value, other.m_value);
  }
};

struct unix_invalid_descriptor_traits {
  using pointer = std::FILE*;
  static pointer invalid() noexcept { return nullptr; }
  static void close(pointer p) noexcept {
    if (p != invalid()) {
      std::fclose(p);
    }
  }
};

using unix_invalid_descriptor =  uniq_descriptor<unix_invalid_descriptor_traits>;

}

#endif
