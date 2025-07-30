/*************************************************************************
    > File Name: leetcode/2875.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月26日 星期六 17时47分35秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        long long total_sum = accumulate(nums.begin(), nums.end(), (long long)0);
        int t = target % total_sum;
        nums.insert(nums.end(), nums.begin(), nums.end());

        long long cur_sum = 0;
        int left  = 0;
        int min_len = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            cur_sum += (long long)nums[i];
            while(cur_sum > t) {
                cur_sum -= (long long)nums[left++];
            }
            if (cur_sum == t) {
                min_len = min(min_len, i - left + 1);
            }
            //std::cout << min_len << std::endl;
        }
        /*
        std::cout << min_len << "\t" << target / total_sum  << "\t"
                  << nums.size() << "\t"
                  << min_len + (target / total_sum) * nums.size()
                  << std::endl;
        */
        if (min_len == INT_MAX) {
            return -1;
        } else {
            return min_len + target / total_sum * nums.size() / 2;
        }
    }
};
