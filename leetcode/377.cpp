/*************************************************************************
    > File Name: leetcode/377.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月09日 星期三 16时28分21秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        std::vector<int> dp(target + 1);
        dp[0] = 1;
        for (int i = 0; i <= target; ++i) {
            if (dp[i] > 0) {
                for (auto n : nums) {
                    if (i + n <= target) {
                        if (int64_t(dp[i+n]) + dp[i] <= INT_MAX) {
                            dp[i + n] += dp[i];
                        }
                    }
                }
            }
        }
        return dp[target];
    }
};
