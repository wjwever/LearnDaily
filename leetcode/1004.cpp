/*************************************************************************
    > File Name: leetcode/1004.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月24日 星期四 22时03分11秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}


class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int max_len = 0;
        int num0 = 0;
        int left = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                ++num0;
            }
            while(num0 > k) {
                int n = nums[left++];
                if (n == 0 ) {
                    --num0;
                }
            }
            max_len = max(max_len, i - left + 1);
        }
        return  max_len;
    }
};
