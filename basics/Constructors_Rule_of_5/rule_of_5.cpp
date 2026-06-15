//In modern C++ (C++11+), if your class manages a resource (like new-allocated memory, file handles, sockets, etc.), and you implement any of these 5 special functions, you should probably implement all 5:
//The  5:
//Destructor
//Copy constructor
//Copy assignment operator
//Move constructor
//Move assignment operator

#include <iostream>
#include <cstring> // for std::memcpy
using namespace std;

class MyArray {
private:
    int* data;
    size_t size;

public:
    // 1. Constructor
    MyArray(size_t s) : size(s) {
        data = new int[size];
        std::cout << "Constructed\n";
    }

    // 2. Destructor
    ~MyArray() {
        delete[] data; //how does delete knows how many elements to clean/free up?
        std::cout << "Destructed\n";
    }

    // 3. Copy constructor (Deep copy)
    MyArray(const MyArray& other) : size(other.size) {
        data = new int[size];
        std::memcpy(data, other.data, size * sizeof(int));
        std::cout << "Copied\n";
    }

    // 4. Copy assignment (Deep copy)
    MyArray& operator=(const MyArray& other) {
        std::cout << "Copy Assigned\n";
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new int[size];
            std::memcpy(data, other.data, size * sizeof(int));
        }
        return *this;
    }

    // 5. Move constructor (Ownership transfer)
    MyArray(MyArray&& other) noexcept : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
        std::cout << "Moved\n";
    }

    // 6. Move assignment (Ownership transfer)
    // By marking move operations as noexcept, you promise the move will never fail.
    MyArray& operator=(MyArray&& other) noexcept {
        std::cout << "Move Assigned\n";
        if (this != &other) {
            delete[] data;//Free old memoryWe call delete[] data; in the move assignment operator to free the resource currently owned by the object, before it takes ownership of a new resource.
            data = other.data;
            size = other.size;

            other.data = nullptr;
            other.size = 0;
        }
        return *this;
    }

    void fill(int val) {
        for (size_t i = 0; i < size; ++i)
            data[i] = val;
    }

    void print() const {
        for (size_t i = 0; i < size; ++i)
            std::cout << data[i] << " ";
        std::cout << "\n";
    }
};

int main() {
    MyArray a1(5);
    a1.fill(42);

    MyArray a2 = a1;         // Copy constructor
    a2.print();

    MyArray a3(3);
    a3 = a1;                 // Copy assignment
    a3.print();

    MyArray a4 = std::move(a1);  // Move constructor
    a4.print();

    MyArray a5(2);
    a5 = std::move(a2);          // Move assignment
    a5.print();
    return 0;
}

