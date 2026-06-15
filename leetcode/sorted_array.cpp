class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j = m - 1;         // Last valid element in nums1
        int k = n - 1;         // Last element in nums2
        int i = m + n - 1;     // End of nums1 array (total size)

        while (j >= 0 && k >= 0) {
            if (nums1[j] > nums2[k]) {
                nums1[i--] = nums1[j--];
            } else {
                nums1[i--] = nums2[k--];
            }
        }

        // If nums2 still has elements, copy them
        while (k >= 0) {
            nums1[i--] = nums2[k--];
        }

    }
};
