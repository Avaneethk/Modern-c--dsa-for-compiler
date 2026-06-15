#include <iostream>
#include <type_traits>

template<typename T>
void check() {
    if constexpr (std::is_pointer<T>::value) {
        std::cout << "Pointer type\n";
    } else {
        std::cout << "Non-pointer type\n";
    }
}

int main() {
    check<int>();      // Non-pointer
    check<int*>();     // Pointer
}

