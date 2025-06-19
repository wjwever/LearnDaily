/*************************************************************************
    > File Name: 70.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年06月19日 星期四 13时46分57秒
 ************************************************************************/
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp (n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};
