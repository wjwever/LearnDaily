/*************************************************************************
    > File Name: leetcode/2905.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月18日 星期五 21时07分49秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int max_idx = 0, min_idx = 0;
        for (int i = indexDifference; i < nums.size(); ++i) {
            if (nums[i - indexDifference] > nums[max_idx]) {
                max_idx = i - indexDifference;
            }
            if (nums[i - indexDifference] < nums[min_idx]) {
                min_idx = i - indexDifference;
            }
            if (abs(nums[i] - nums[max_idx]) >= valueDifference) {
                return  {max_idx, i};
            }
            if (abs(nums[i] - nums[min_idx]) >= valueDifference) {
                return {min_idx, i};
            }
        }
        return {-1, -1};
    }
};

int main()
{
    vector<int> data = {7,6,3,5,9,5};
    Solution s;
    s.findIndices(data, 2, 6);
    return 0;
}

