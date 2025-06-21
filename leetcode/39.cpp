/*************************************************************************
    > File Name: leetcode/39.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年06月20日 星期五 15时00分46秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> vec;
        dfs(candidates, target, 0, vec);
        return res;
    }
    void dfs(vector<int>& candidates, int target, int sum, vector<int>& vec, int step = 0)  {
        if (sum > target) {
            return;
        }
        if (sum == target) {
            res.push_back(vec);
        }
        for (int i = step; i < candidates.size(); ++i) {
            sum += candidates[i];
            vec.push_back(candidates[i]);
            dfs(candidates, target, sum, vec, i);
            sum -=  candidates[i];
            vec.pop_back();
        }
    }
};

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // dp[i][target] = dp[i][target-c[i]];
        // i    yong 0, 1 2, 3
        int row = candidates.size();
        vector<vector<int>> dp(row, vector<int>(target + 1, 0));
        for (int a = 0; a < row; ++a) {
            for (int b = 0; b < target + 1; ++b) {
               if (b == 0)  {
                    dp[a][b] = 0;
                    continue;
               }
               int times = 0;
               while(times * candidates[a] <= b) {
                   dp[a][b] += dp[a-1][target-times*candidates[a]];
                   times ++;
               }
            }
        }
        return dp[row][target];
    }
};

int main()
{
    return 0;
}

