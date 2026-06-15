#include<iostream>
#include<stack>

using namespace std;

class Answer{
    public:
    static bool check(string sequence){
        stack<char> s;
        
        for(char ch:sequence)
        {
            if(ch=='['||ch=='(')
            {
                s.push(ch);//store all the right open in stack
            }
            else if(ch==']'||ch==')')
            {
                if(s.empty()) return false;
                char top = s.top();
                s.pop();
                if((ch==']' && top != '[')||(ch==')'&&top !='(')) return false;
            }
        }
        return s.empty();
        
    }
}
