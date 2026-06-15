#include<iostream>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): data(x), left(NULL), right(NULL) {}
};

void degree_max_sum(TreeNode* root, int& max_sum){
    if(!root) return;
    
    int degree = root->data;
    if(root->left) degree += root->left->data;
    if(root->right) degree += root->right->data;

    if(degree > max_sum) max_sum = degree;

    degree_max_sum(root->left, max_sum);
    degree_max_sum(root->right, max_sum);
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    int max_sum = 0;
    degree_max_sum(root, max_sum);
    cout << "Max degree sum: " << max_sum << endl;

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}