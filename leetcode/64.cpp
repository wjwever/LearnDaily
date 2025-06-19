/*************************************************************************
    > File Name: 64.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年06月19日 星期四 15时32分13秒
 ************************************************************************/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int ROW = grid.size();
        int COL = grid[0].size();
        for (int col = 1; col < COL; ++col) {
            grid[0][col] += grid[0][col-1];
        }

        for (int row = 1; row < grid.size(); ++row) {
            grid[row][0] +=  grid[row-1][0];
            for (int col = 1; col < grid[row].size(); ++col) {
                grid[row][col] += min(grid[row][col-1], grid[row-1][col]);
            }
        }

        for (int r = 0; r < ROW; ++r) {
            for(int c = 0; c < COL; ++c) {
                std::cout << grid[r][c] << " ";
            }
            std::cout << "\n";
        }

        return grid[ROW-1][COL-1];
    }
};
