#include <iostream>

void print() {
    std::cout << "Done\n";
}

template <typename T, typename... Args>
void print(T first, Args... rest) {
    std::cout << first << " ";
    print(rest...);
}

int main() {
    print(1, 2.5, "hello", 'x');
}

