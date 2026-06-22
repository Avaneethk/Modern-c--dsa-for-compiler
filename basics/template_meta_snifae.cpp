// Compile with: g++ -std=c++17 -O2 -Wall -Wextra sfinae_example.cpp
#include <iostream>
#include <string>
#include <type_traits>
#include <utility>

// -----------------------------
// 1. Template metaprogramming
// Compile-time factorial via class template recursion
template <unsigned N>
struct Factorial {
  static constexpr unsigned value = N * Factorial<N - 1>::value;
};

template <>
struct Factorial<0> {
  static constexpr unsigned value = 1;
};

// -----------------------------
// 2. Detection idiom (std::void_t) to test for a member expression
template <typename, typename = void>
struct has_size : std::false_type {};

template <typename T>
struct has_size<T, std::void_t<decltype(std::declval<T>().size())>> : std::true_type {};

// Helper variable template
template <typename T>
inline constexpr bool has_size_v = has_size<T>::value;

// -----------------------------
// 3. SFINAE with std::enable_if
// a) Enable function only for integral types
template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
T add_one(T x) {
  return x + 1;
}

// b) Overload selected via SFINAE using the detection idiom
//    If T has size(), return that size; otherwise return -1.
template <typename T>
std::enable_if_t<has_size_v<T>, std::size_t> get_size(const T &t) {
  return t.size();
}

template <typename T>
std::enable_if_t<!has_size_v<T>, int> get_size(const T &) {
  return -1;
}

// -----------------------------
// Demo
int main() {
  // Template metaprogramming: compile-time factorial
  std::cout << "Factorial<5>::value = " << Factorial<5>::value << '\n';

  // SFINAE with enable_if for integral types
  int a = 10;
  std::cout << "add_one(10) = " << add_one(a) << '\n';
  // double d = 3.14;
  // add_one(d); // error if uncommented: add_one is not viable for non-integral types

  // Detection idiom + SFINAE
  std::string s = "hello";
  std::cout << "get_size(string) = " << get_size(s) << '\n';
  std::cout << "get_size(int) = " << get_size(42) << '\n'; // returns -1

  return 0;
}
