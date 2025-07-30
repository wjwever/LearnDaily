/*************************************************************************
    > File Name: leetcode/2610.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月16日 星期三 20时31分52秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        std::map<int, int> book;
        for (auto n : nums) {
            ++book[n];
        } 
        int max_sum = 0;
        for (auto& [k, v] : book) {
            max_sum = max(max_sum, v);
        }
        vector<vector<int>> res;
        res.resize(max_sum);

        for (auto& [k, v] : book) {
            for (int i = 0; i < v; ++i) {
                res[i].push_back(k);
            }
        }

        return res;
    }
};
