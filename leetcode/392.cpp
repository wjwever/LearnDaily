class Solution {
public:
    bool isSubsequence(string s, string t) {
       int m = s.size() , n = t.size() ;
       vector<vector<int>> dp;
       dp.resize(m + 1, vector<int>(n + 1, 1));

       std::cout << 1 << std::endl;
       for (int r = 0; r < m; ++r) {
            dp[r][n] = 0;
       }
       std::cout << 2 << std::endl;

        for (int a = m - 1; a >= 0; --a) {
            for (int b = n - 1; b >= 0; --b) {
                if (s[a] == t[b]) {
                    dp[a][b] = dp[a+1][b+1];
                } else {
                    dp[a][b] = dp[a][b+1];
                }
            }
        }
        return dp[0][0];
    }
};
