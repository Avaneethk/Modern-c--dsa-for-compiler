#include <iostream>

template <typename T>
void printType() {
    std::cout << "Generic type\n";
}

template <>
void printType<int>() {
    std::cout << "int type\n";
}

template <>
void printType<double>() {
    std::cout << "double type\n";
}

int main() {
    printType<char>();    // Generic
    printType<int>();     // Specialized
    printType<double>();  // Specialized
}

