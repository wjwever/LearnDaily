/*************************************************************************
    > File Name: leetcode/3371.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月17日 星期四 15时49分50秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}
class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int sum = 0;
        for (auto n : nums) {
            sum += n;
        }

        unordered_map<int, int> cnt;
        for (auto n : nums) {
            ++cnt[n];
        }

        int res = INT_MIN;
        for (int i =0; i < nums.size(); ++i) {
            --cnt[nums[i]];
            int val = (sum - nums[i]) / 2;
            //std::cout << val << " " << cnt[val] << " " << nums[i] << std::endl;
            if (cnt[val] and val * 2 == sum - nums[i]) {
                res = max(res, nums[i]);
            }
            ++cnt[nums[i]];
        } 
        return res;
    }
};
