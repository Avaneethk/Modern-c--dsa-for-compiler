#include <iostream>
#include <string>
#include <utility>
using namespace std;
//universal reference 
void process(const std::string& s) {
    std::cout << "Lvalue processed: " << s << '\n';
}

void process(std::string&& s) {
    std::cout << "Rvalue processed: " << s << '\n';
}

template <typename T>
void forwarder(T&& arg) {
    std::cout << "Inside wrapper\n";
    process(std::forward<T>(arg));  // Preserves lvalue or rvalue
}

int main() {
    std::string name = "Avaneeth";

    forwarder(name);              // Calls lvalue version
    forwarder(std::move(name));   // Calls rvalue version

    return 0;
}

