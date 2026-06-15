//Virtual functions enable runtime polymorphism in C++.
//They are implemented using a vtable (virtual function table).
//Each class with virtual functions has its own vtable.
//Each object of such a class has a hidden pointer to this table called the vptr.

#include<iostream>
using namespace std;

class Base{
	public:
		virtual void display()
		{
			cout<<"Inside the base class"<<endl;
		}
	};
class Derived : public Base {
	public:
		void display() override{
			cout<<"Inside the derived class"<<endl;
		}
};

int main()
{
	//Derived object is allocated on heap.
        //It is assigned to a Base* pointer.
        //No explicit cast is needed (implicit conversion allowed).
        //This is safe, because the base class part always exists in the derived object.
        
	//Since display() is virtual, and bptr actually points to a Derived object,
        //The call is dispatched at runtime (i.e., dynamically) via the vtable.
        //So Derived::display() will be called.
        //This is runtime polymorphism in action.

	Base* bptr = new Derived(); //upcasting derived to Base 
	bptr->display();//calls the derived class function as the vptr points to the vtable of derived class
	return 0;
}

