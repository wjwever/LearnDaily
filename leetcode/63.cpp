/*************************************************************************
    > File Name: 63.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年06月19日 星期四 15时53分59秒
 ************************************************************************/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int ROW = obstacleGrid.size();
        int COL = obstacleGrid[0].size();
        vector<vector<int>> dp(ROW);
        for (auto& vec : dp) vec.resize(COL, 1);

        for (int i = 0; i < ROW; ++i) {
            for (int j = 0; j < COL; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else if (i == 0 and j == 0) {
                    dp[i][j] = 1;
                }  else if (i == 0) {
                    dp[i][j] = dp[i][j - 1];
                } else if (j == 0) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[ROW-1][COL-1];
    }
};

