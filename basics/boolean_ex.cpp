#include<iostream>
using namespace std;
bool isEqual(int x, int y)
{
	return x==y;
}
int main()
{
	cout<<"Enter an integer:"<<endl;
	int x{};
	cin>>x;
	cout<<"Enter 2nd integer:"<<endl;
	int y{};
	cin>>y;
	cout<<"check if they are equal :"<<isEqual(x,y)<<endl;
	return 0;
}


