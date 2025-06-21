/*************************************************************************
    > File Name: leetcode/17.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年06月20日 星期五 13时39分24秒
 ************************************************************************/
class Solution {
public:
    vector<string> res;
    vector<string> phone = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxzy"};
    vector<string> letterCombinations(string digits) {
        std::string curRes;
        dfs(digits, 0, curRes);
        return res;
    }
    void dfs(const string& digits, int step, std::string curRes) {
        if (step == digits.size()) {
            if (curRes.size() > 0) {
                res.push_back(curRes);
            }
            return;
        }
        int d = digits[step] - '2';
        for (char c : phone[d]) {
            curRes.push_back(c);
            dfs(digits, step + 1, curRes);
            curRes.pop_back();
        }
    }
};
