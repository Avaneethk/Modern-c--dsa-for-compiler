#include <iostream>
//Use variadic templates when you need functions or types that accept an arbitrary number of type parameters or compile‑time values 
template<typename... T>

void printAll(const T... args) 
{
  //The fold expression ((expr), ...) expands the pack and evaluates expr for each element.
  ((std::cout << args << ' '),...);
}

int main() {

  printAll(1, "hello", 3.14, 'x');

  return 0;
}
