#include<iostream>

//Virtual inheritance prevents multiple base class copies by ensuring only one shared instance exists in the most-derived class.

//It achieves this via virtual base pointers (vptrs) that are managed at runtime.

using namespace std;

class A{
    public:
	void show()
	{
	  cout<<"Inside show"<<endl;
	}
};
class B: virtual public A{
};

class C: virtual public A{
};

class D: virtual public B,virtual public C{
};

int main()
{
	D obj;
	obj.show();
	return 0;
}
