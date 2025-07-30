/*************************************************************************
    > File Name: leetcode/485.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月10日 星期四 22时41分40秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxRes = 0;
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if(nums[i]) {
                ++res;
            }else {
                res = 0;
            }
            maxRes = max(maxRes, res);
        }
        return maxRes;
    }
};
