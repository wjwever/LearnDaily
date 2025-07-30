/*************************************************************************
    > File Name: leetcode/1658.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月24日 星期四 22时43分06秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        int del = sum - x;
        if (del < 0) {
            return -1;
        }

        int cur_sum = 0;
        int left = 0;
        int max_len = -1;
        for (int i = 0; i < nums.size(); ++i) {
            cur_sum += nums[i];
            while(cur_sum > del) {
                auto val = nums[left++];
                cur_sum-= val;
            }
            if (cur_sum == del) {
                max_len = max(max_len, i - left + 1);
            }
        }
        if (max_len == -1) {
            return -1;
        }  else {
            return nums.size() - max_len;
        }
    }
};
