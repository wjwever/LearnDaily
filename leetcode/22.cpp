/*************************************************************************
    > File Name: leetcode/22.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年06月20日 星期五 17时42分20秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        //left >= right
        std::string cur;
        dfs(n, 0, 0, cur);
        return res;
    }
    void dfs(int num, int left, int right, std::string& cur) {
        if (left == num and right == num) {
            res.push_back(cur);
            return ;
        }
        if (left < num) {
            cur += "(";
            dfs(num, left + 1, right, cur);
            cur.pop_back();
        }
        if (right < left and right < num) {
            cur += ")";
            dfs(num, left , right + 1, cur);
            cur.pop_back();
        }
    }
};

int main()
{
    return 0;
}

