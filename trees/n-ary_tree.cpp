#include<iostream>
#include<vector>

using namespace std;

struct Node{
    int val;
    vector<Node*>children;
    Node(int x):val(x){
        cout<<"Inside the Node constructor"<<endl;
    }
};

void preorder(Node* root)
{
    if(!root) return ;
    cout<<root->val<<endl;
    for(Node* child:root->children){
        preorder(child);
    }
}

int main()
{
    //create node of n-ary tree
    Node* root = new Node(1);
    Node* child1 = new Node(2);
    Node* child2 = new Node(3);
    Node* child3 = new Node(4);
    Node* child4 = new Node(5);
    
    //build tree
    root->children.push_back(child1);
    root->children.push_back(child2);
    root->children.push_back(child3);
    root->children.push_back(child4);
    
    preorder(root);
    
    return 0;

}
