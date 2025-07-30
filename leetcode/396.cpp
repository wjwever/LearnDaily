/*************************************************************************
    > File Name: leetcode/396.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月09日 星期三 18时28分51秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
       int f = 0, n = nums.size();
       int numSum  = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < n; i++) {
            f += i * nums[i];
        }
        int res = f;
        for (int i = n -1; i>0; --i) {
            f += numSum - n * nums[i];
            res = max(res, f);
        }
       return res;
    }
};
