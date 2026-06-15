#include <iostream>
//CRTP is used for static polymorphism — avoiding virtual tables at compile-time.

template <typename Derived>
class Base {
public:
    void interface() {
        static_cast<Derived*>(this)->implementation();
    }
};

class DerivedA : public Base<DerivedA> {
public:
    void implementation() {
        std::cout << "DerivedA implementation\n";
    }
};

int main() {
    DerivedA obj;
    obj.interface();  // Calls DerivedA::implementation via CRTP
}

