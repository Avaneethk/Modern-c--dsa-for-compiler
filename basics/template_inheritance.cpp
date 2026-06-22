#include <iostream>
#include <utility>

//No extra memory.
//Zero cost abstraction.

//Bring all constructors from the base class (std::pair) into this derived class
//using std::pair<KeyT, ValueT>::pair; constructor inheritance 
template<typename IdT, typename NameT>
struct StudentPair : std::pair<IdT,NameT> //StudentPair inherits the std::pair and defines its own functions
{
    IdT& getId()
    {
        return std::pair<IdT,NameT>::first;
    }

    NameT& getName()
    {
        return std::pair<IdT,NameT>::second;
    }
};
// const KeyT &getFirst() const { 
//I will return a value but you are not allowed to modify it 
//int &x =s.getid();
//getid which is a member of s should return int& (a reference to a member inside s)
// x becomes alias to that internal member
//modyifying x modifies s with const it does not happen 
// why it retures & ? operator chaining 
//second const belongs to function and it promises it does not modify the object 
//"This function returns a read-only reference to a KeyT, and calling this function will not modify the object itself."
int main()
{
    StudentPair<int,std::string> student;

    student.first = 101;
    student.second = "Alice";

    std::cout << student.getId() << "\n";
    std::cout << student.getName() << "\n";
    return 0;
}