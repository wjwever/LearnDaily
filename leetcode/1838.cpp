/*************************************************************************
    > File Name: leetcode/1838.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月26日 星期六 16时04分19秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
       sort (nums.begin(), nums.end());
       int max_len = 1;
       long long cur_sum = 0;
       int left = 0;
       for (int i = 1; i < nums.size(); ++i) {
            cur_sum += (long long)(nums[i] - nums[i-1])* (i - left);
            while(cur_sum > k) {
                auto diff = nums[i] - nums[left++];
                cur_sum -= diff;
            }
            max_len = max(max_len, i - left + 1);
       }
       return max_len;
    }
};
