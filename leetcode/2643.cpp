/*************************************************************************
    > File Name: leetcode/2643.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月15日 星期二 22时10分51秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}


class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int max_row = 0, max_count = 0;
        int row = 0;
        for (auto & vec : mat) {
            int count = std::accumulate(vec.begin(), vec.end(), 0);
            if (count > max_count) {
                max_count = count;
                max_row = row;
            }
            row ++;
        }
        return {max_row, max_count};
    }
};
