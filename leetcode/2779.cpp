/*************************************************************************
    > File Name: leetcode/2779.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月25日 星期五 20时25分18秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort (nums.begin(), nums.end());
        int left = 0;
        int max_len = 0;
        for (int i = 0; i < nums.size(); ++i) {
            while(nums[i] - nums[left] > 2 * k) {
                ++left;
            }
            max_len = max(max_len, i - left + 1);
        }
        return max_len;
    }
};
