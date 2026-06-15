#include<iostream>
using namespace std;

class Base {
public:
    virtual void show() { std::cout << "Base\n"; }
};

class Derived : public Base {
public:
    void show() override { std::cout << "Derived\n"; }
    void onlyInDerived() { std::cout << "Extra Derived Stuff\n"; }
};

int main() {
    Derived d;
    Base* b = &d;  //  Upcast: broader scope
    b->show();     // Prints "Derived" due to virtual

    // b->onlyInDerived();  Error: only visible in Derived

    Derived* dptr = dynamic_cast<Derived*>(b); //  Downcast
    dptr->onlyInDerived();  //  OK now
    return 0;
}

