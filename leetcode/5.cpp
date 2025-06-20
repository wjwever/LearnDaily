/*************************************************************************
    > File Name: leetcode/5.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年06月19日 星期四 18时18分37秒
 ************************************************************************/
class Solution {
public:
    string longestPalindrome(string s) {
        // f(a, b) => f(a+1, b-1)
        // perfect => f(a-1, b-1)
        //f(8, 8) = 1
        //f(7,8)
        //f(6,8) = f(7, 7) f(6, 7) f(6, 6) (6, 8) => f(7,7)
        int strLen = s.size();
        vector<vector<int>> dp(strLen);
        for (auto& vec: dp) vec.resize(strLen, 0);
        int maxLen = 1;
        std::string curStr = s.substr(0, 1);
        for (int row = strLen-1; row >=0; --row){
            for (int col = row; col < strLen; ++col) {
                if (row == col) {
                    dp[row][col] = 1;
                } else if (col - row == 1) {
                    dp[row][col] =  s[row] == s[col];
                    if (dp[row][col] and 2 > maxLen ) {
                        maxLen = 2;
                        curStr = s.substr(row, 2);
                        std::cout << "curStr:" << curStr << std::endl;
                    }
                } else {
                    dp[row][col] = s[row] == s[col] && dp[row+1][col-1];
                    if (dp[row][col] and col - row + 1 > maxLen) {
                        maxLen =  col - row + 1;
                        curStr = s.substr(row, maxLen);
                        std::cout << "curStr:" << curStr << std::endl;
                    }
                }
            }
        }
        return curStr;
    }
};
