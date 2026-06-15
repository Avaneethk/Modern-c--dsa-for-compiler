#include<iostream>
//const expr -> compile time
//const ->possiblity of both compile and runtime 

using namespace std;

constexpr int max_of(int a , int b)
{
	return (a>b)? a : b ;
}

int main()
{
	constexpr int max_val = max_of(5,7);
	int com_array[10];
	cout<<"Array size:"<<sizeof(com_array)/sizeof(int) <<endl;
	cout<<"max_val :"<<max_val<<endl;
	return 0;
}

