/*************************************************************************
    > File Name: leetcode/2962.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月27日 星期日 10时09分26秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int max_val = INT_MIN;
        for (auto n : nums) max_val = max(max_val, n);

        int cnt = 0;
        int left = 0;
        long long ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == max_val) ++cnt;
            while(cnt >= k) {
                auto n = nums[left++];
                if (n == max_val) --cnt;
            }
            ans += left;
        }
        return ans;
    }
};
