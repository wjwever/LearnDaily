class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int id1 = m - 1, id2 = n -1, id  = m + n -1;
        while(id >= 0) {
            if (id1 >= 0 and id2 >= 0) {
                if (nums1[id1] > nums2[id2]) {
                    nums1[id--] = nums1[id1--];
                } else {
                    nums1[id--] = nums2[id2--];
                }
            } else if (id1 >= 0) {
                nums1[id--] = nums1[id1--];
            } else if (id2 >= 0) {
                nums1[id--] = nums2[id2--];
            }
        }
    }
};
