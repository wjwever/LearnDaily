class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curMax = 0, Max = INT_MIN;
        for (auto n : nums) {
            curMax += n;
            Max = max(Max, curMax);
            if (curMax < 0) {
                curMax = 0;
            }
        }
        return Max;
    }
};
