/*************************************************************************
    > File Name: leetcode/2090.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月19日 星期六 21时34分37秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res(n, -1);
        if (n < 2 * k + 1) {
            return res;
        }

        long long sum = 0LL;
        sum = std::accumulate(nums.begin(), nums.begin() + 2 * k, 0LL);
        for (int i = k; i < nums.size() - k; ++i) {
            sum += nums[i + k];
            res[i] = sum / (2 * k + 1);
            sum -= nums[i - k];
        }
        return res;
    }
};
