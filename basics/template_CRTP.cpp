#include <iostream>
//The base class is a class template parameterized by the derived type.
template<typename Derived>
class Shape {
public:

    void render() {
        std::cout << "Start Drawing\n";

        // Call function in derived class
        
        static_cast<Derived*>(this)->draw();

        std::cout << "End Drawing\n";
    }
};

class Circle : public Shape<Circle> {
public:

    void draw() {
        std::cout << "Drawing Circle\n";
    }
};

class Square : public Shape<Square> {
public:

    void draw() {
        std::cout << "Drawing Square\n";
    }
};

int main() {

    Circle c;
    Square s;

    c.render();
    s.render();
}