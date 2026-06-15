class solution{
public:
ListNode* addtwinum(ListNode* L1,ListNode* L2)
{
  ListNode* dummy = new ListNode(0);
  ListNode* curr = dummy;
  int carry=0;

while(L1!=nullptr || l2!=nullptr || carry)
{
int sum =carry;
if(L1!=nullptr)
{
sum+=L1->val;
L1=L1->next;
}
if(L2!=nullptr)
{
sum+=L2->val;
L2=L2->next;
}
carry = sum/10;
curr->next = new List(sum%10);
curr = curr->next;
}
return dummy->next;
delete dummy;
delete curr;
}



