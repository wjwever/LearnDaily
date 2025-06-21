/*************************************************************************
    > File Name: leetcode/46.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年06月20日 星期五 14时42分22秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> book;
    vector<vector<int>> permute(vector<int>& nums) {
        int len = nums.size();
        book.resize(len, 0);
        vector<int> vec;
        dfs(0, nums, vec);
        return res;
    }
    void dfs(int step, vector<int>&nums, vector<int>& vec) {
        if (vec.size() >= nums.size()) {
            res.push_back(vec);
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (book[i] == 0) {
                book[i] = 1;
                vec.push_back(nums[i]);
                dfs(step+1, nums, vec);
                book[i] = 0;
                vec.pop_back();
            }
        }
    }
};

int main()
{
    return 0;
}

