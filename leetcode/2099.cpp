/*************************************************************************
    > File Name: leetcode/2099.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月13日 星期日 12时47分06秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        std::vector<size_t> idx(nums.size());
        std::iota(idx.begin(), idx.end(), 0);
        std::sort(idx.begin(), idx.end(), [&nums](int id1, int id2) {
            return nums[id1] > nums[id2];
        });
        vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(idx[i]);
        }
        sort (res.begin(), res.end());

        vector<int> ret;
        for (auto c : res) {
            ret.push_back(nums[c]);
        }
        return ret;
    }
};
