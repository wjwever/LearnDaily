/*************************************************************************
    > File Name: leetcode/2597.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月16日 星期三 20时16分18秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution {
public:
    std::map<int, int> data;
    int res = 0;
    int beautifulSubsets(vector<int>& nums, int k) {
        dfs(nums, 0, k);
        return res-1;
    }
    void dfs(vector<int>& nums, int step, int k) {
        if (step >= nums.size()) {
            ++res;
            return;
        }
        dfs(nums, step + 1, k);
        if (data[nums[step] - k] == 0 and data[nums[step] + k] == 0) {
            ++data[nums[step]];
            dfs(nums, step + 1, k);
            --data[nums[step]];
        }
    }
};
