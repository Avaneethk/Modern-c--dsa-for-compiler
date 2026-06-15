//Construction order: Base → Derived
//When you create a Derived object, the Base constructor runs first, then the Derived constructor.
//Destruction order: Derived → Base
//When an object is destroyed, destructors are called in reverse order: first the Derived destructor, then the Base destructor.
//If the destructor is virtual, the object has a vptr pointing to the vtable.
//delete basePtr; looks up the destructor function pointer in the vtable.
//The call resolves dynamically to Derived::~Derived().
//The destructor chain (Derived::~Derived() → Base::~Base()) executes correctly.

//Memory Layout of Derived Object
//Offset	Contents	Description
//0	vptr	Pointer to Derived's vtable
//8 or 4	Data members	(if any, here none)
//Vtable for Derived
//Index	Function Pointer	Notes
//0	RTTI info	Runtime type information
//1	Derived::foo()	Virtual function override
//2	Derived::~Derived()	Virtual destructor override

#include <iostream>

class Base {
public:
    virtual ~Base() {
        std::cout << "Base destructor called\n";
    }
};

class Derived : public Base {
public:
    ~Derived() override {
        std::cout << "Derived destructor called\n";
    }
};

int main() {
    Base* ptr = new Derived();
    delete ptr;  // Correctly calls Derived destructor first, then Base destructor
    return 0;
}

