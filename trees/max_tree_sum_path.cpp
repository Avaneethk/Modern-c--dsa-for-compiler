#include <iostream>
#include <vector>
using namespace std;

class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

// Helper function to find maximum sum path and store the path
void maxSumPath(Node *node, int currentSum, int &maxSum, 
                vector<int> &currentPath, vector<int> &maxPath) {
    
    if (node == nullptr) return;

    // Add current node to path and sum
    currentSum += node->data;
    currentPath.push_back(node->data);

    // If leaf node, check and update maxSum and maxPath
    if (node->left == nullptr && node->right == nullptr) {
        if (currentSum > maxSum) {
            maxSum = currentSum;
            maxPath = currentPath;
        }
    } else {
        // Recurse into left and right
        maxSumPath(node->left, currentSum, maxSum, currentPath, maxPath);
        maxSumPath(node->right, currentSum, maxSum, currentPath, maxPath);
    }

    // Backtrack
    currentPath.pop_back();
}

// Function to get the maximum sum from root to leaf and the path
int maxRootToLeafSum(Node *root, vector<int> &maxPath) {
    int maxSum = 0;
    vector<int> currentPath;
    maxSumPath(root, 0, maxSum, currentPath, maxPath);
    return maxSum;
}

int main() {
    // Build the tree
    //        1
    //       / \ 
    //      2   3 
    //     /\   /
    //    4  5 6 
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    vector<int> maxPath;
    int maxSum = maxRootToLeafSum(root, maxPath);

    cout << "Maximum root-to-leaf sum: " << maxSum << endl;
    cout << "Path: ";
    for (int val : maxPath) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
