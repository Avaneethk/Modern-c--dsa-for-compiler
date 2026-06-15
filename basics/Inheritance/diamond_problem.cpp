//The diamond problem in C++ is a specific ambiguity that arises in multiple inheritance scenarios. It occurs when a class inherits from two or more classes that share a common base class. This creates a "diamond" shape in the inheritance hierarchy: 
//     a
//   /   \
//  b     c
//   \  /
//    d

//without virtual 
//diamond_problem.cpp: In function ‘int main()’:
//
//diamond_problem.cpp:32:13: error: request for member ‘show’ is ambiguous
//  32 |         obj.show();
//     |             ^~~~
//diamond_problem.cpp:14:22: note: candidates are: ‘void A::show()’
//   14 |                 void show()
//      |                      ^~~~
//diamond_problem.cpp:14:22: note:                 ‘void A::show()’
//avaneeth@avaneeth-virtual-machine:~/Programming-for-Compiler-Dev/Cl
//
//
//
#include<iostream>
using namespace std;

class A {
	public:
		void show()
		{
			cout<<"Inside A show()"<<endl;
		}
};
class B:public A {
};

class C:public A{
};

class D:public B,public C
{
};

int main()
{
	D obj;
	obj.show();
	return 0;
}





