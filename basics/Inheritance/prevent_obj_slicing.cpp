#include <iostream>
using namespace std;

class Base {
public:
    int a = 1;
    virtual void print() {
        cout << "Base\n";
    }
};

class Derived : public Base {
public:
    int b = 2;
    void print() override {
        cout << "Derived\n";
    }
};

int main() {
    Derived d;
    Base* b = &d;      //  Object slicing happens here
    b->print();
    return 0;    // What does this print?
}

