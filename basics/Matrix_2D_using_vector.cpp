#include <iostream>
#include <vector>

int main() {
    int rows, cols;
    std::cout << "Enter number of rows and columns: ";
    std::cin >> rows >> cols;

    // Create a 2D vector with given rows and columns, initialized to 0
    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols, 0));

    // Read matrix values
    std::cout << "Enter matrix elements:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    // Write (print) matrix
    std::cout << "\nMatrix:\n";
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
`
