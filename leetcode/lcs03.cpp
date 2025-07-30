/*************************************************************************
    > File Name: lcs03.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月30日 星期三 21时52分54秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution {
public:
    int _cnt = 0;
    int _max_cnt = 0;
    int largestArea(vector<string>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        std::vector<std::vector<int>> vis(row, std::vector<int>(col,0));
        std::function<void(int , int , char, int&)> dfs = [&](int i, int j, char val, int& near) {
            if (i < 0 || j < 0 || i >= row || j >= col) {
                near = 1;
                return;
            }
            if (grid[i][j] == '0') {
                near = 1;
            };
            if (vis[i][j] || grid[i][j] != val) {
                return;
            }
            vis[i][j] = 1;
            ++_cnt;
            //std::cout << val << '\t' << near << '\t' << i << '\t' << j << '\t' << _cnt << '\n';
            dfs(i - 1, j, val, near);
            dfs(i + 1, j, val, near);
            dfs(i, j - 1, val, near);
            dfs(i, j + 1, val, near);
        };
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (vis[i][j] == 0) {
                    int near = 0;
                    _cnt = 0;
                    dfs(i, j, grid[i][j], near);
                    //std::cout << "test:" << i << "\t" << j << "\t" << near << "\n";
                    if (near == 0) {
                        _max_cnt = max(_max_cnt, _cnt);
                    }
                }
            }
        }
        return _max_cnt;
    }
};
