#include<iostream>
using namespace std;

template<typename T>
T square(T a)
{
	return a*a;
}

int main()
{
	cout<<square(2)<<endl;
	cout<<square(1.5)<<endl;
	return 0;
}
