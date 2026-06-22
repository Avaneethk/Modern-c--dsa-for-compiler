#include<iostream>

using namespace std;

//template<typename>

/*
template<typename T>
using MyVector = std::vector<T>;
*/

template<typename T>
T mul(T x)
{
    return x*x;
}

int main()
{
    int x = mul(4);
    auto y = mul(4.44);

    cout<<"X :"<<x<<endl;
    cout<<"Y :"<<y<<endl;
    return 0;
}