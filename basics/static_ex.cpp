#include<iostream>
using namespace std;

//static variables retains its value between the function call with its lifetime as programs lifetime
//static function belongs to the class not to any object 
//static class means a class with only static members 
//Linkage determines the visiblity 
//static variable/function at file scope has internal linkage and only visible within the file where it is defined 
//NOt accessible form other files
//static variable cannot be initialized using constructors
//as the variables declared as static are initialized only once as they are allocated space in seperate storage we cannot have multiple copies 
void staticexample()
{
	static int count =0;
	count++;
	cout<<"Static variable count :"<<count<<endl;
}

class myclass{
	public:
	 static void staticfunc()
	 {
		 cout<<"static func called"<<endl;
	 }
};

class staticclass {
	public:
		static int value ;
		static void show(){
			cout<<"Staticclass value"<< value<<endl;
		}
		

};
int staticclass::value = 42;

int main()
{
	staticexample();
	staticexample();

	myclass::staticfunc();
	staticclass::show();
	staticclass::value=100;
	staticclass::show();
	return 0;}








