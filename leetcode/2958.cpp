/*************************************************************************
    > File Name: leetcode/2958.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月24日 星期四 22时31分36秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int max_len = 0;
        int left = 0;
        std::map<int, int> cnt;
        for (int i = 0; i < nums.size(); ++i) {
            ++cnt[nums[i]];
            while(cnt[nums[i]] > k) {
                auto c = nums[left++];
                --cnt[c];
            }
            max_len = max(max_len, i - left + 1);
        }
        return max_len;
    }
};
