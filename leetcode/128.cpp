class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        std::sort(nums.begin(), nums.end());
        int res = 1;
        int cur = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] - nums[i-1] == 1){
                ++cur;
            } else if (nums[i] - nums[i - 1] == 0) {
                cur = cur;
            }  else {
                cur = 1;
            }
            res = max(res, cur);
        }
        return res;
    }
    
};
