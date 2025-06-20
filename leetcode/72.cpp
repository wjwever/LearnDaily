/*************************************************************************
    > File Name: leetcode/72.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年06月19日 星期四 20时54分52秒
 ************************************************************************/

class Solution {
public:
    int minDistance(string word1, string word2) {
       int len1 = word1.size(), len2 = word2.size();
       std::vector<std::vector<int>> dp(len1 + 1);
       for (auto& vec: dp) vec.resize(len2 + 1, 0);

       for (int a = 0; a < len1 + 1; a++) {
            for (int b=0; b < len2 + 1; b++) {
                if (a == 0) {
                    dp[a][b] = b;
                } else if (b == 0) {
                    dp[a][b] = a;
                } else if (word1[a-1] == word2[b-1]) {
                    dp[a][b] = dp[a-1][b-1];
                } else {
                    dp[a][b] = 1 + min(min(dp[a-1][b-1], dp[a][b-1]), dp[a-1][b]);
                }
            }
       }
        return dp[len1][len2];
    }
};
