class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result=0;
        int count1=0;
        
        for(int k=0;k<=31;k++)
        {
            int temp=1<<k;
            for(int num:nums)
            {
                if((num&temp)!=0) count1++;
            }
            if(count1%3==1)
            result=result|temp;
            
            count1=0; //reset 
        }
       return result;
        
    }
};
