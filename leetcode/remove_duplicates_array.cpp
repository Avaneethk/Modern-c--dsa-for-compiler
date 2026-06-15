class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    //Two pointer approach
    int arr_size=nums.size();
        int i=0;
        for(int j=1;j<arr_size;j++)
        {
            if(nums[j]!=nums[i])
            {
            i++;
            nums[i]=nums[j];
            }
        }
 
    return i+1;
    }
};
