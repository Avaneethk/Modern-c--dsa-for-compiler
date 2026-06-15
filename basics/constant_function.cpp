//A constant function is a member function that does not modify the state of the object 

//syntax returntype function(args) const
//It will not modify any non static data members 
//only const member function can be called on const objects 
//const obj can invoke const member function
//if we want to modify a specific data member within a const member mutable keyword to be used
//const functions can be called by non const objects where as nonconst member function can be called on non-const objects
 
#include<iostream>
using namespace std;

class Point{
	int x,y;
	public:
	  Point(int a , int b):x(a),y(b) {}
	  int getX() const {return x;}
	  int getY() const {return y;}
	  void setX(int a ) {x=a;}
};

int main(){
	Point p(3,4);
	cout<<p.getX()<<endl;
	p.setX(5);
	return 0;
}
