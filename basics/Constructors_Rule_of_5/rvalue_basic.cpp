#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int& lref = a;        // lvalue reference
    // int& lref2 = 5;    //  Error: can't bind lvalue ref to rvalue

    int&& rref = 5;       //  rvalue reference (C++11)
    cout << rref << endl;

    rref = 100;           // You can modify it
    cout << rref << endl;

    return 0;
}
//int&& is a rvalue reference: it can bind to temporary values (like 5).
//Rvalue references enable move semantics, which can optimize performance by avoiding unnecessary copies.

