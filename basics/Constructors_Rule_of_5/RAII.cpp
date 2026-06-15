//RAII stands for:Resource Acquisition Is Initialization
//It's a C++ technique where resources (like memory, file handles, mutexes, etc.) are acquired in a constructor and released in a destructor.
//Ensures automatic cleanup
//Works with stack allocation (destructor runs automatically when object goes out of scope)
//Great for exception safety

#include <iostream>
#include <fstream>

class FileRAII {
private:
    std::ofstream file;

public:
    FileRAII(const std::string& filename) {
        file.open(filename);
        if (file.is_open()) {
            std::cout << "File opened successfully\n";
        } else {
            std::cerr << "Failed to open file\n";
        }
    }

    void write(const std::string& data) {
        if (file.is_open()) {
            file << data << "\n";
        }
    }

    ~FileRAII() {
        if (file.is_open()) {
            file.close();
            std::cout << "File closed automatically\n";
        }
    }
};

int main() {
    
        FileRAII writer("output.txt");
        writer.write("Hello from RAII-managed file!");
        // destructor is called here when `writer` goes out of scope local or at the end of main

    return 0;
}

