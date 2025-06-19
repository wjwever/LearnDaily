/*************************************************************************
    > File Name: 300.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年06月19日 星期四 14时42分01秒
 ************************************************************************/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int numsLen = nums.size();
        int maxLen = 1;
        vector<int> dp(numsLen, 1);
        for (int i = 1; i < numsLen; ++i) {
            for (int k = 0; k < i; ++k) {
                if (nums[k] < nums[i]) {
                    dp[i] = max(dp[i], dp[k] + 1);
                }
                maxLen = max(maxLen, dp[i]);
            }
        }
        for (auto d : dp) {
            std::cout << d << " ";
        }
        std::cout << "\n";
        return maxLen;
    }
};
