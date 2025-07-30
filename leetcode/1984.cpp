/*************************************************************************
    > File Name: leetcode/1984.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月22日 星期二 11时28分13秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int min_res = INT_MAX;
        for (int i = k - 1; i < nums.size(); ++i) {
          min_res = min(min_res, nums[i] - nums[i - k + 1]);
        }
        return min_res;
    }
};
