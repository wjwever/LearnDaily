/*************************************************************************
    > File Name: leetcode/2441.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月17日 星期四 14时07分41秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        std::set<int> data;
        int max_res = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (data.count(-nums[i])) {
                max_res = max(max_res, abs(nums[i]));
            }
            data.insert(nums[i]);
        }
        return max_res;
    }
};
