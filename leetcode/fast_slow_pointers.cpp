#include<iostream>
using namespace std;

struct ListNode{
int val;
ListNode* next;
ListNode(int x):val(x),next(nullptr){}
};

ListNode* findMiddle(ListNode* head)
{
  ListNode* slow = head;
  ListNode* fast = head;

  while(fast!=nullptr && fast->next!=nullptr)
{
slow=slow->next;
fast=fast->next->next;
}
return slow;
}
