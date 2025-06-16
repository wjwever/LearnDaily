class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
       int beg = 0, end = nums.size() - 1;
       while (beg <= end) {
            if (nums[beg] != val) {
                ++beg;
            } else if (nums[end] == val) {
                --end;
            } else {
                std::swap(nums[beg++], nums[end--]);
            }
       }
       return end + 1;
    }
};
