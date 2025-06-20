/*************************************************************************
    > File Name: leetcode/200.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年06月20日 星期五 11时22分49秒
 ************************************************************************/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
       int row = grid.size(), col = grid[0].size();
       int num = 0;
       for (int a = 0; a < row; ++a) {
            for (int b = 0; b < col; ++b) {
                if (grid[a][b] == '1') {
                    ++num;
                    dfs(a, b, grid);
                }
            }
       }
       return num;
    }

    void dfs (int a, int b, vector<vector<char>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int dirs[4][2] = {{-1,0}, {1, 0}, {0,-1}, {0, 1}};
        if (a < 0 or a >= row or b < 0 or b >= col or grid[a][b]=='0') {
            return;
        } else {
            grid[a][b] = '0';
            for (auto dir : dirs) {
                dfs(a+dir[0], b+dir[1], grid);
            }
        }
    }
};
