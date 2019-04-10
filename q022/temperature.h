#ifndef _TEMPERATURE_H_
#define _TEMPERATURE_H_

#include <istream>
#include <ostream>

namespace cpp_challenge {

using value_type = long double;

template <typename Traits>
class temperature {
private:
  long double _absolute_temperature;
public:
  explicit constexpr temperature(value_type const src) noexcept
  : _absolute_temperature{ Traits::conversion(src) }
  {}

  explicit constexpr temperature() noexcept
  : temperature{0.0}
  {}

  template <typename OtherTraits>
  explicit constexpr temperature(temperature<OtherTraits> const & other) noexcept
  : _absolute_temperature{ other._absolute_temperature }
  {}

  template <typename OtherTraits>
  constexpr temperature& operator=(temperature<OtherTraits> const & other) noexcept {
    _absolute_temperature = other._absolute_temperature;
    return *this;
  }

  template <typename OtherTraits>
  constexpr temperature<Traits> const operator+(temperature<OtherTraits> const & other) const noexcept {
    value_type cur = get();
    value_type dest = Traits::exchange(OtherTraits::conversion(other.get()));
    return temperature<Traits>{ cur + dest };
  }

  template <typename OtherTraits>
  constexpr temperature<Traits> const operator-(temperature<OtherTraits> const & other) const noexcept {
    value_type cur = get();
    value_type dest = Traits::exchange(OtherTraits::conversion(other.get()));
    return temperature<Traits>{ cur - dest };
  }

  template <typename OtherTraits>
  constexpr temperature<Traits> const operator*(temperature<OtherTraits> const & other) const noexcept {
    value_type cur = get();
    value_type dest = Traits::exchange(OtherTraits::conversion(other.get()));
    return temperature<Traits>{ cur * dest };
  }

  template <typename OtherTraits>
  constexpr temperature<Traits> const operator/(temperature<OtherTraits> const & other) const noexcept {
    value_type cur = get();
    value_type dest = Traits::exchange(OtherTraits::conversion(other.get()));
    return temperature<Traits>{ cur / dest };
  }

  template <typename T>
  constexpr temperature const operator+(T const & v) const noexcept {
    return temperature{ get() + v };
  }

  template <typename T>
  constexpr temperature const operator-(T const & v) const noexcept {
    return temperature{ get() - v };
  }

  template <typename T>
  constexpr temperature const operator*(T const & v) const noexcept {
    return temperature{ get() * v };
  }

  template <typename T>
  constexpr temperature const operator/(T const & v) const noexcept {
    return temperature{ get() / v };
  }

  constexpr void set(value_type&& src) noexcept {
    _absolute_temperature = Traits::conversion(src);
  }

  constexpr value_type const get() const noexcept {
    return Traits::exchange(_absolute_temperature);
  }

  template <typename OtherTraits>
  operator temperature<OtherTraits> () noexcept {
    return temperature<OtherTraits>{ OtherTraits::exchange(_absolute_temperature) };
  }

  friend std::istream& operator>> (std::istream& is, temperature& t) {
    value_type input;
    is >> input;
    t.set(input);
    return is;
  }

  friend std::ostream& operator<< (std::ostream& os, temperature const & t) {
    os << t.get();
    return os;
  }
};

struct degree_celsius_traits {
  static constexpr value_type exchange(value_type at) noexcept {
    return at - 273.15;
  }
  static constexpr value_type conversion(value_type dc) noexcept {
    return dc + 273.15;
  }
};

struct kelvin_traits {
  static constexpr value_type exchange(value_type at) noexcept {
    return at;
  }
  static constexpr value_type conversion(value_type at) noexcept {
    return at;
  }
};

struct degree_fahrenheit_traits {
  static constexpr value_type exchange(value_type at) noexcept {
    return at * 9.0 / 5.0 - 459.67;
  }
  static constexpr value_type conversion(value_type df) noexcept {
    return (df + 459.67) * 5.0 / 9.0;
  }
};

using degree_celsius = temperature<degree_celsius_traits>;
using kelvin = temperature<kelvin_traits>;
using degree_fahrenheit = temperature<degree_fahrenheit_traits>;

  namespace temperature_literals {
    degree_celsius operator"" _deg(long double deg) {
      return degree_celsius{ deg };
    }

    kelvin operator"" _k(long double k) {
      return kelvin{ k };
    }

    degree_fahrenheit operator"" _f(long double f) {
      return degree_fahrenheit{ f };
    }
  }
}

#endif
