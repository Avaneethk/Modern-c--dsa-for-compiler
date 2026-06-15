#include<iostream>
using namespace std;

void modify(int *x) {
    *x = *x + 10;
}

int main() {
    int a = 5;
    modify(&a);
    cout << a;  // Output: 15 (original changed)
}

/*
 Use pass by reference when you want simple, safe access to modify a variable.

Use pass by pointer when you need to deal with nullability, dynamic memory, or reassignment of what the variable refers to.*/
/*
 * A pointer can be:

Uninitialized

Pointing to a valid memory address

nullptr

You must always check if the pointer is valid before dereferencing to avoid crashes*/
/*
 * A reference in C++ must refer to an existing variable at the time of declaration.

You cannot have a null or uninitialized reference.

Once set, a reference cannot be changed to refer to another variable.*/
