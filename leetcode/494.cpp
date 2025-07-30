/*************************************************************************
    > File Name: leetcode/494.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月10日 星期四 18时22分09秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}
class Solution {
public:
    int count = 0;
    int target = 0;
    int findTargetSumWays(vector<int>& nums, int target) {
        this->target = target;
        run(nums, 0, 0); 
        return count;
    }

    void run(vector<int>& nums, int step, int sum) {
        if (step >= nums.size()) {
            if (sum == target) {
                //std::cout << sum << std::endl;
                ++count;
            }
            return;
        }
        sum += nums[step];
        run(nums, step + 1, sum);
        sum -= nums[step];

        sum -= nums[step];
        run(nums, step + 1, sum);
        sum += nums[step];
    }
};
