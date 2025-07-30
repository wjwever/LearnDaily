/*************************************************************************
    > File Name: leetcode/2461.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月20日 星期日 09时18分09秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ret = INT_MIN;
        long long sum = 0;
        std::unordered_map<int, int> cnt;
        int left = 0;
        for (int i = 0; i < nums.size(); ++i) {
            //std::cout << left << "\t" << i << "\t" << ret << std::endl;
            sum += nums[i];
            ++cnt[nums[i]];
            while (cnt[nums[i]] > 1) {
                sum -= nums[left];
                --cnt[nums[left++]];
            }
            if (i - left + 1 < k) {
                continue;
            }
            if (sum > ret) {
                ret = sum;
            }
            sum -= nums[left];
            --cnt[nums[left++]];
        }
        return ret == INT_MIN ? 0 : ret;
    }
};
