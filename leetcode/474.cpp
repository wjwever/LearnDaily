/*************************************************************************
    > File Name: leetcode/474.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月11日 星期五 16时37分52秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution {
public:
    std::pair<int, int> get_size_pair(const std::string& str) {
        int num0= 0, num1 = 0;
        for (auto c : str) {
            if (c == '0') {
                ++num0;
            } else {
                ++num1;
            }
        }
        return std::make_pair(num0, num1);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        int length = strs.size();
        vector<vector<vector<int>>> dp(length + 1, vector<vector<int>>(m + 1, vector<int>(n + 1)));

        for (int i =  1; i <= strs.size(); ++i) {
            auto sizes = get_size_pair(strs[i - 1]);
            for (int a = 0; a <= m; ++a) {
                for (int b = 0; b <= n; ++b) {
                    dp[i][a][b] = dp[i-1][a][b];
                    if (a >= sizes.first and b >= sizes.second) {
                        dp[i][a][b] = max(dp[i][a][b], 1 + dp[i - 1][a-sizes.first][b-sizes.second]);
                    }
                }
            }
        }

        return dp[length][m][n];
    }
};
