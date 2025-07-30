/*************************************************************************
    > File Name: 16.19.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月30日 星期三 21时52分26秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution {
public:
    vector<vector<int>> vis;
    int cur_max = 0;
    vector<int> pondSizes(vector<vector<int>>& land) {
        int row = land.size();
        int col = land[0].size();
        vis.resize(row, vector<int>(col, 0));
        std::function<void(int, int, int)> dfs = [&](int i, int j, int mark) {
            if (i < 0 || j < 0 || i >= row || j >= col || vis[i][j] || land[i][j]) {
                return;
            }
            vis[i][j] = 1;
            ++cur_max;
            std::cout << i << "\t" << j << "\t" << cur_max << "\n";
            for (int a = -1; a <= 1; ++a) {
                for (int b = -1; b <= 1; ++b) {
                    dfs(i + a, j + b, mark + 1);
                }
            }
        };
        std::vector<int> vec;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (vis[i][j] == 0 and land[i][j] == 0) {
                    cur_max = 0;
                    dfs(i, j, 1);
                    vec.push_back(cur_max);
                }
            }
        }
        sort(vec.begin(), vec.end());
        return vec;
    }
};
