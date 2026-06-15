//Object slicing occurs when a derived class object is assigned or passed by value to a base class variable or function argument.
//The extra data and behavior specific to the derived class are sliced off — only the base part remains.
//

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
    Base b = d;      //  Object slicing happens here
    b.print();       // What does this print?
    return 0;
}

