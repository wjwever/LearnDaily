/*************************************************************************
    > File Name: leetcode/136.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年06月20日 星期五 21时40分15秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int a = nums[0];
       for (int i = 1; i < nums.size(); ++i) {
            a ^= nums[i];
       }
       return a;
    }
};

int main()
{
    return 0;
}

