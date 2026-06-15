#include<iostream>
using namespace std;

namespace MyNamespace {
	int MyVar=10;
	void MyFunction()
	{
		cout<<"Inside namespace"<<endl;
	}
}

int main()
{
	int myVar=5;
	MyNamespace::MyFunction();
	int local = MyNamespace::MyVar;
	cout<<"Local"<<local<<endl;
	cout<<"myVar"<<myVar<<endl;
	return 0;
}
