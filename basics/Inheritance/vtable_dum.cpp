#include <iostream>
using namespace std;

class Base {
public:
    int x;
    virtual void foo() {
        cout << "Base::foo\n";
    }
};

class Derived : public Base {
public:
    int y;
    void foo() override {
        cout << "Derived::foo\n";
    }
};

int main() {
    Derived d;
    Base* b = &d;
    b->foo();  // Should call Derived::foo
    return 0;
}

