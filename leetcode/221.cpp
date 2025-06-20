/*************************************************************************
    > File Name: leetcode/221.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年06月20日 星期五 08时09分40秒
 ************************************************************************/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> dp(row);
        for (auto& vec : dp) vec.resize(col, 0);
        int maxL = 0;
        for (int a = 0; a < row; ++a) {
            for (int b = 0; b < col; ++b) {
                if (matrix[a][b] == '1') {
                    if (a==0 or b==0) {
                        dp[a][b] = 1;
                    } else {
                        dp[a][b]= 1 + min(min(dp[a-1][b], dp[a][b-1]), dp[a-1][b-1]);
                    }
                    maxL = max(maxL, dp[a][b]);
                }
            }
        }
        return maxL * maxL;
    }
};
