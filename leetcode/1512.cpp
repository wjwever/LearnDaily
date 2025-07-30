/*************************************************************************
    > File Name: leetcode/1512.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月17日 星期四 14时17分28秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int res = 0;
        map<int, int> cnt;
        for (int i = 0; i < nums.size(); ++i) {
            res += cnt[nums[i]];
            ++cnt[nums[i]];
        }
        return res;
    }
};
