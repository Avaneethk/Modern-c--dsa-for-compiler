#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

//write a reverse linked list function

Node* reverse(Node* root)
{
	Node* prev = nullptr;
	Node* current = root;
	while(current!=nullptr)
	{
	  Node* next  = current->next;//2
	  current->next = prev;//make 1 as null
          prev = current;
	  current = next;
	 
	}
	return prev;

}

//create a linked list using the above ADT
int main()
{
	//1->2->3->
	Node* root = new Node{1,nullptr};
        Node* N1 = new Node{2,nullptr};
        Node* N2 = new Node{3,nullptr};

        root->next = N1;
        N1->next = N2;
        
        //cout<<"Address pointing by root"<<root<<endl;
	Node* reverse_root = reverse(root);
        while(reverse_root!=nullptr)
	{
		cout<<reverse_root->data<<endl;
		reverse_root=reverse_root->next;
	}
     	return 0;
}	

