/*************************************************************************
    > File Name: leetcode/594.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月13日 星期日 18时11分30秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort (nums.begin(), nums.end());
        int beg = 0, ed = 0;
        int max_res = 0;
        while(ed < nums.size()) {
            auto diff = nums[ed] - nums[beg];
            if (diff == 0) {
                ++ed;
            } else if (diff == 1) {
                max_res = max(max_res, ed - beg + 1);
                ++ed;
            } else {
                ++beg;
            }
        }
        return max_res;
    }
};
