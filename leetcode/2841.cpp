/*************************************************************************
    > File Name: leetcode/2841.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月20日 星期日 09时35分21秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}
class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        std::map<int, int> cnt; 
        long long sum = 0;
        long long max_sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            ++cnt[nums[i]];
            if (i < k - 1) {
                continue;
            }
            if (cnt.size() >= m) {
                max_sum = max(max_sum, sum);
                std::cout << i << '\t' << cnt.size() << '\t' <<  max_sum << '\n';
            }
            sum -= nums[i-k+1];
            if (--cnt[nums[i -k + 1]] == 0) {
                cnt.erase(nums[i-k + 1]);
            }
        }
        return max_sum;
    }
};
