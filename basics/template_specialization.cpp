#include <iostream>
#include <string>

// Primary template
template<typename T>
struct Printer {
  static void print(const T &v) {
    std::cout << "generic: " << v << '\n';
  }
};

// Full specialization for int
template<>
struct Printer<int> {
  static void print(const int &v) {
    std::cout << "int-specialized: " << v << '\n';
  }
};

int main() {
  Printer<double>::print(3.14);// uses primary template
  Printer<std::string>::print("hi");
  Printer<int>::print(42);// uses explicit specialization
  
  return 0;
}
