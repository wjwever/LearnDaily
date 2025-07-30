/*************************************************************************
    > File Name: leetcode/376.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月09日 星期三 18时44分00秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> dp(len, vector<int>(2, 1)); // greater less

        for (int i = 1; i < len; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i][0] = max(dp[i][0], dp[j][1] + 1);
                }
                if (nums[i] < nums[j]) {
                    dp[i][1] = max(dp[i][1], dp[j][0] + 1);
                }
            }
        }
        return max(dp.back()[0], dp.back()[1]);
    }
};
