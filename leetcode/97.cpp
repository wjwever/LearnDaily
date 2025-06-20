/*************************************************************************
    > File Name: leetcode/97.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年06月19日 星期四 19时20分32秒
 ************************************************************************/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
       if (s1.size() + s2.size() != s3.size()) {
        return false;
       }
        // dp[a][b] == if (s1[a] == s3[a+b])
       int row  = s1.size(), col  = s2.size();
       vector<vector<int>> dp(row + 1);
       for (auto& vec : dp) vec.resize(col + 1 , 0);
       dp[0][0] = 1;

        for (int a = 0; a < row + 1 ; ++a) {
            for (int b = 0; b < col + 1 ; ++b) {
                if (a == 0 ) {
                    if (b > 0 and dp[a][b-1] == 1 and s2[b -1] == s3[b -1]) {
                        dp[a][b] = 1;
                    }
                } else if (b == 0) {
                    if (a > 0 and dp[a-1][b] and s1[a-1] == s3[a-1]) {
                        dp[a][b] = 1;
                    }
                } else {
                    if (s1[a-1] == s3[a+b-1] and dp[a-1][b]) {
                        dp[a][b] = 1;
                    }
                    if(s2[b-1] == s3[a+b-1] and dp[a][b-1]) {
                        dp[a][b] = 1;
                    }
                }
                std::cout << a << " " << b << " " << dp[a][b] << std::endl;
            }
        }
        return dp[row ][col];
    }
};
