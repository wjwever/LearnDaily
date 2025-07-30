/*************************************************************************
    > File Name: leetcode/2016.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月17日 星期四 14时35分32秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int min_val = nums[0]; 
        int res = -1;
        for (int i = 1; i < nums.size(); ++i) {
            res = max(res, nums[i] - min_val);
            min_val = min(min_val, nums[i]);
        }
        return res <= 0 ? -1 : res;
    }
};
