/*************************************************************************
    > File Name: leetcode/643.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月19日 星期六 20时50分18秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
       double sum = 0;
       double max_sum = INT_MIN;
       for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (i < k - 1) {
                continue;
            }
            max_sum = max(max_sum, sum);
            sum -= nums[i - k + 1];
       }
       return max_sum / k;
    }
};
