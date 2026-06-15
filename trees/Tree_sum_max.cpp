#include<iostream>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):data(x),left(nullptr),right(nullptr){} 
};
int treesum(TreeNode* root)
{
    if(!root) return 0;
    else
    return root->data+treesum(root->left)+treesum(root->right);

}
int main()
{
    TreeNode* root = new TreeNode(1);
    TreeNode* N1 = new TreeNode(2);
    TreeNode* N2 = new TreeNode(3);
    TreeNode* N3 = new TreeNode(4);
    TreeNode* N4 = new TreeNode(5);

    root->left = N1;
    root->right = N2;
    root->left->left = N3;
    root->left->right = N4;

    int sum = treesum(root);
    cout<<"Tree sum :"<<sum<<endl;

    return 0;
    
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

}