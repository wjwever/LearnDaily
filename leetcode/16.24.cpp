/*************************************************************************
    > File Name: leetcode/16.24.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月17日 星期四 15时07分36秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}
class Solution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        map<int, int> cnt;
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (cnt[target - nums[i]]) {
                res.emplace_back();
                res.back().push_back(nums[i]);
                res.back().push_back(target - nums[i]);
                --cnt[target-nums[i]];
            } else {
                ++cnt[nums[i]];
            }
        }
        return res;
    }
};
