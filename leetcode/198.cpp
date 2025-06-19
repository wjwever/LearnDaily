/*************************************************************************
    > File Name: 198.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年06月19日 星期四 13时58分34秒
 ************************************************************************/
class Solution {
public:
    int rob(vector<int>& nums) {
        int numsLen = nums.size();
        vector<vector<int>>dp (numsLen);
        for(auto& ele : dp) {
            ele.resize(2, 0);
        }

        dp[0][0] = 0;
        dp[0][1] = nums[0];
        for (int i = 1; i < numsLen; ++i) {
            std::cout << "i " << i << std::endl;
            dp[i][0] = max(dp[i-1][1], dp[i-1][0]);
            dp[i][1] = dp[i-1][0] + nums[i];
        }
        return max(dp[numsLen-1][0], dp[numsLen-1][1]);
    }
};
