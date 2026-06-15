#include<iostream>
using namespace std;

//Base* basePtr = new Derived();
//This is an upcast (safe, implicit).
//Even though the pointer is of type Base*, the object is a Derived.

//2. dynamic_cast<Derived*>(basePtr);
//This is a downcast (potentially unsafe).
//Only works if Base is polymorphic (i.e., has at least one virtual function).
//If basePtr actually points to a Derived, the cast succeeds.

//3. delete basePtr;
//Because Base destructor is virtual, both Derived and Base destructors are called in proper order.
//If Base's destructor was not virtual, only Base's destructor would be called — Derived's destructor would be skipped (bad!).

class Base{
	public:
		Base(){
			cout<<"Inside the base const"<<endl;
		}
	     virtual	~Base(){
			cout<<"Inside the base dest"<<endl;
		}};
class Derived:public Base{
	public:
		Derived(){
			cout<<"Inside the derived const"<<endl;
		}
		~Derived() override {
			cout<<"Inside the derived dest"<<endl;
		}};
int main()
{
	
	//Base* B = new Base();
	//Base* B = new Derived();//upcast safe
	//Derived* D = new dynamic_cast<Base>();
	//Derived d;
	//nheritance_basic.cpp:41:22: error: cannot ‘dynamic_cast’ ‘B’ (of type ‘class Base*’) to type ‘class Derived*’ (source type is not polymorphic)
//   41 |         Derived* D = dynamic_cast<Derived*>(B);//down cast not safe if the class in not polymorphic

	//Base* B = new Base();
        Base* B = new Derived();
        Derived* D = dynamic_cast<Derived*>(B);//down cast not safe if the class in not polymorphic
	//delete D;
	delete D;
	return 0;
}
