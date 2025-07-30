/*************************************************************************
    > File Name: leetcode/384.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月09日 星期三 16时47分55秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}
class Solution {
public:
    Solution(vector<int>& nums) {
        this->orignal = nums;
        this->nums = nums;
    }
    
    vector<int> reset() {
        return orignal; 
    }
    
    vector<int> shuffle() {
        for (int i = 0; i <nums.size(); ++i) {
            int j = i + rand() %(nums.size() -i);
            swap(nums[i], nums[j]);
        }
        return nums; 
    }
    vector<int> orignal;
    vector<int> nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
