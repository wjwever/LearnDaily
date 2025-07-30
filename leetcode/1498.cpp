/*************************************************************************
    > File Name: leetcode/1498.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月15日 星期二 15时29分17秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}


class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = static_cast<int>(nums.size());
        sort(nums.begin(), nums.end());
        int left = 0, right = n - 1;
        long long res = 0;
        while (left <= right) {
            while (left <= right && nums[left] + nums[right] > target) {
                --right;
            }
            if (left > right) {
                break;
            }
            res = (res + fastPow(2, right - left)) % MOD;
            ++left;
        }
        return static_cast<int>(res);
    }

private:
    const int MOD = static_cast<int>(1e9 + 7);
    int fastPow(long long base, int pow) {
        long long res = 1;
        while (pow != 0) {
            if (pow % 2 != 0) {
                res = res * base % MOD;
            }
            base = base * base % MOD;
            pow >>= 1;
        }
        return res;
    }
};
