/*************************************************************************
    > File Name: 139.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年06月19日 星期四 14时15分58秒
 ************************************************************************/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int strLen = s.size();
        vector<int> dp(strLen + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < strLen; ++i) {
            if (dp[i]) {
                for (auto& word : wordDict) {
                    if (s.substr(i, word.size()) == word) {
                        dp[i + word.size()] = 1;
                    }
                    if (dp[strLen]) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
