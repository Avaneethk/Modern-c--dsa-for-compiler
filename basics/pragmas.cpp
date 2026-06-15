#include<iostream>
using namespace std;

#define MY_NAME "Alex"
#define MY_NAME "Ale"

//duplicates is allowed bu the latest def is considered

int main()
{
	cout<<"My Name is :"<<MY_NAME<<endl;
        cout<<"My Name is :"<<MY_NAME<<endl;
	return 0;
}
