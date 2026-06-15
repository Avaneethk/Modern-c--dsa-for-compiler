#include <iostream>
#include <type_traits>

template<typename T>
typename std::enable_if<std::is_integral<T>::value>::type
printType(T) {
    std::cout << "Integral type\n";
}

template<typename T>
typename std::enable_if<std::is_floating_point<T>::value>::type
printType(T) {
    std::cout << "Floating point type\n";
}

int main() {
    printType(10);     // Integral
    printType(3.14);   // Floating point
}

