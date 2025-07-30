/*************************************************************************
    > File Name: 1020.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月30日 星期三 21时53分46秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size(); 
        int max_cnt = 0;
        std::vector<std::vector<int>> vis(row, vector<int>(col, 0));

        std::function<void(int, int, int&, int&)> dfs = [&](int i, int j, int& cnt, int& edge) {
            if (i < 0 || i >= row || j < 0 || j >= col) {
                edge = 1;
                return;
            }
            if (grid[i][j] == 0) {
                return;
            }
            if (vis[i][j]) return;
            vis[i][j] = 1;
            ++cnt;
            //std::cout << i << "\t" << j << "\t" << cnt << "\t" << edge << "\n";
            dfs(i + 1, j, cnt, edge);
            dfs(i - 1, j, cnt, edge);
            dfs(i, j + 1, cnt, edge);
            dfs(i, j - 1, cnt, edge);
        };

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                int edge = 0;
                int cnt = 0;
                if (grid[i][j] == 1) {
                    dfs(i, j, cnt, edge);
                    //std::cout << "test:" << i << '\t' << j  << '\t' << cnt << '\t' << edge << '\n';
                    if (edge == 0) {
                        max_cnt += cnt;
                    }
                }
            }
        }
        return max_cnt;
    }
};

