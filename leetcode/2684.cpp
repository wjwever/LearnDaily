/*************************************************************************
    > File Name: 2684.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月30日 星期三 21时54分40秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
       int row = grid.size(), col = grid[0].size();
       vector<vector<int>> dp(row, vector<int>(col, -1)); 
       for (int i = 0; i < row; ++i) dp[i][0] = 0;
       int max_res = 0;
       for (int j = 1; j < col; ++j) {
           for (int i = 0; i < row; ++i) {
               if (grid[i][j] > grid[i][j - 1] and dp[i][j-1] >= 0) {
                   dp[i][j] = max(dp[i][j], 1 + dp[i][j - 1]);
               } 
               if (i > 0 and grid[i][j] > grid[i-1][j-1] and dp[i-1][j-1] >= 0) {
                   dp[i][j] = max(dp[i][j], 1 + dp[i-1][j-1]);
               }
               if (i + 1 < row and grid[i][j] > grid[i+1][j-1] and dp[i+1][j-1] >= 0) {
                   dp[i][j] = max(dp[i][j], 1 + dp[i+1][j-1]);
               }
               max_res = max(max_res, dp[i][j]);
           }
       }
       return max_res;
    }
};
