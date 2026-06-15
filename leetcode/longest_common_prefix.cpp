class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

         int min=strs[0].length();
         for(auto it =strs.begin();it!=strs.end();it++)
         {
            int length = it->length();
            if(length<min)
            {
                min=length;
            }
         }
        //sort
        sort(strs.begin(),strs.end());
        string common_prefix="";
        string first = strs[0];
        string last = strs[strs.size()-1];
        //compare
        for(int i=0;i<min;i++)
        {
         if(first[i]==last[i])
         common_prefix+=first[i];
         else
         {
            break;
         }
        }

    return common_prefix;
          
    }
};
