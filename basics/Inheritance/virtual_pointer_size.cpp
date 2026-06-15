#include <iostream>
using namespace std;

class Base {
public:
    virtual void display() {}
};

class Derived : public Base {
public:
    void display() override {}
};

int main() {
    cout << "Size of Base: " << sizeof(Base) << endl;
    cout << "Size of Derived: " << sizeof(Derived) << endl;
}

