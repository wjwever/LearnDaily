/*************************************************************************
    > File Name: leetcode/491.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月11日 星期五 12时00分43秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution {
public:
    vector<vector<int>> data;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int N = nums.size();
        vector<int> res;
        dfs(nums, res, 0, 0);
        return data;
    }
    void dfs(const vector<int>& nums, vector<int>& res, int start, int step) {
        //std::cout << step << " " << start << std::endl;
        if (res.size() >= 2) {
            data.emplace_back(res);
        }
        if (start >= nums.size()) {
            return;
        }

        std::set<int>  book;
        for (int i = start; i < nums.size(); ++i) {
            if (book.count(nums[i])) {
                continue;
            }
            book.insert(nums[i]);
            if (res.empty() or nums[i] >= res.back()) {
                book.insert(nums[i]);
                //std::cout << "step:" << step << "->" << nums[i] << std::endl;
                res.push_back(nums[i]);
                dfs(nums, res, i + 1, step + 1);
                res.pop_back();
            }
        }
    }
};
