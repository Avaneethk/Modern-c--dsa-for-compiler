#include<iostream>
//this pointer is a special c++ pointer available inside the non-static member function of a class it points ti the object for which member function is called
//In class A inside a non static member fucntion this is of type A* const
//Allows access to the calling object's members and methods
//used to distinguish between the member variable and parameters with same name , enable method chaining and pass the currect object as argument 
//this pointer is not available in static member functions since they are not associated with any object 
using namespace std;

class Counter {
	int value ;
	public:
	 Counter(int v=0) : value(v) {}
	 
	 //set value using this pointer
	 //
	 Counter& set(int v) {
		 this->value = v;
		 return *this;
	 }

	 Counter& increment(){
		 this->value++;
		 return *this;
	 }
	 void print() const{
		 cout<<"Counter value: "<<this->value<<endl;
	 }
};

int main()
{
	Counter c;
	c.set(5).increment().increment().print();

	return 0;
}

