class Solution {
public:
    vector<int> plusOne(vector<int>& digits) { 
        int length = digits.size()-1;
        int carry=0;
        digits[length]+=1;
        for(int i=length;i>=0;i--)
        {
          digits[i]+=carry;
          carry=digits[i]/10;
          digits[i]=digits[i]%10;
    
        }
        if(carry==1)
        {
          digits.insert(digits.begin(),1); 
        }
        return digits;
    }
};
