class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums; 
        int len1 = nums1.size(), len2 = nums2.size();

        int id1 = 0,  id2 = 0;
        while(nums.size() < (len1 + len2) / 2 + 1) {
            if (id1 < nums1.size() and id2 < nums2.size()) {
                if (nums1[id1] < nums2[id2]) {
                    //std::cout << "p1\n";
                    nums.push_back(nums1[id1++]);
                } else {
                    //std::cout << "p2\n";
                    nums.push_back(nums2[id2++]);
                }
            } else if (id1 < nums1.size()) {
                //std::cout << "p1\n";
                nums.push_back(nums1[id1++]);
            } else  {
                std::cout << "p2\n";
                nums.push_back(nums2[id2++]);
            }
        }

        for (auto c : nums) {
            std::cout << c << std::endl;
        }
        if ((len1 + len2) % 2 == 0) {
            int len = nums.size();
            return 0.5 *( nums[len -1] + nums[len -2]);
        } else {
            return nums.back(); 
        }
    }
};
