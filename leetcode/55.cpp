class Solution {
public:
    bool canJump(vector<int>& nums) {
        int curMax = 0;
        if (nums.size() < 2) {
            return true;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (curMax >= i) {
                curMax = max(i + nums[i], curMax);
            }
        }
        return curMax >= nums.size() - 1;
    }

};
