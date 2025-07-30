/*************************************************************************
    > File Name: leetcode/2831.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月26日 星期六 20时41分17秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < n; i++) {
            pos[nums[i]].emplace_back(i);
        }
        int ans = 0;
        for (auto &[_, vec] : pos) {
            /* 缩小窗口，直到不同元素数量小于等于 k */
            for (int i = 0, j = 0; i < vec.size(); i++) {
                while (vec[i] - vec[j] - (i - j) > k) {
                    j++;
                }
                ans = max(ans, i - j + 1);
            }
        }
        return ans;
    }
};

