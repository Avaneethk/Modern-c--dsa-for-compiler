#include<iostream>
using namespace std;

int main()
{
	int row=2,col=3;
	int** arr = new int*[row]; //array of row pointers
        
        for(int i=0;i<row;i++)
		arr[i]=new int[col]; //for each row assign column number of pointers which creates a 2D array


	int val=1;
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			arr[i][j]=val++;

	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			cout<<arr[i][j]<<endl;
	//free memory first all rows and then columns 
	for(int i=0;i<row;i++)
		delete[] arr[i];
	delete[] arr;

	return 0;
}

