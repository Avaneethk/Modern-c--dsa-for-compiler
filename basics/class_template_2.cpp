#include <iostream>
#include <stdexcept>

template<typename T, int N>
class Array {
    T input[N];

public:
    // index operator for non-const objects
    T &operator[](int i) {
        if (i < 0 || i >= N) throw std::out_of_range("Index out of range");
        return input[i];
    }

    // index operator for const objects
    const T &operator[](int i) const {
        if (i < 0 || i >= N) throw std::out_of_range("Index out of range");
        return input[i];
    }

    int size() const { return N; }
};

int main() {
    Array<int, 10> a;          // correct template instantiation
    a[0] = 42;                 // uses operator[]
    a[1] = 7;

    for (int i = 0; i < a.size(); ++i) {
        std::cout << "a[" << i << "] = " << a[i] << '\n';
    }

    // const usage
    const Array<int, 10> &ca = a;
    std::cout << "ca[0] = " << ca[0] << '\n';

    return 0;
}
