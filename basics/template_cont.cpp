#include <iostream>

template<typename T>
class Box
{
private:
    T value;

public:

    Box(T v)
    {
        value = v;
    }

    const T &getValue() const
    {
        return value;
    }
};

//Inside this function, I promise not to change the object's data members. and return value is also const reference

int main()
{
    Box<int> b(100);

    const int &x = b.getValue();

    std::cout << x << std::endl;
}