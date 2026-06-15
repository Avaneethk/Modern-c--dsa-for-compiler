#include <iostream>
#include <type_traits>

template<typename T>
void impl(T x, std::true_type) {
    std::cout << "Pointer overload: " << *x << '\n';
}

template<typename T>
void impl(T x, std::false_type) {
    std::cout << "Value overload: " << x << '\n';
}

template<typename T>
void dispatch(T x) {
    impl(x, std::is_pointer<T>());
}

int main() {
    int a = 5;
    int* p = &a;
    dispatch(p);  // Pointer overload
    dispatch(a);  // Value overload
}

