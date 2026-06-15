#include<iostream>
using namespace std;

int abs(int a )
{
	if(a<0)
		return -a;
	else
		return a;

}

int main()
{
	int x,y;
	cout<<"Enter a value:"<<endl;
	cin>>x;
	y=abs(x);
	cout<<"Abs value is :"<<y<<endl;
	return 0;
}
