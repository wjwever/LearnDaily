/*************************************************************************
    > File Name: leetcode/40.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年06月20日 星期五 16时03分32秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> vec;
        dfs(candidates, target, 0, vec);
        return res;
    }
    void dfs(vector<int>& candidates, int target, int sum, vector<int>& vec, int step = 0)  {
        if (sum > target) {
            return;
        }
        if (sum == target) {
            if (res.empty() or vec != res.back()) {
                res.push_back(vec);
            }
        }
        for (int i = step; i < candidates.size(); ++i) {
            if (i > step and candidates[i] == candidates[i - 1]) {
                continue;
            }
            sum += candidates[i];
            vec.push_back(candidates[i]);
            dfs(candidates, target, sum, vec, i + 1);
            sum -=  candidates[i];
            vec.pop_back();
        }
    }
};

int main()
{
    return 0;
}

