/*************************************************************************
    > File Name: leetcode/2138.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月15日 星期二 16时06分30秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}


class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;
        std::string tmp;
        for (int i = 0; i < s.size(); ++i) {
            if (tmp.size() == k) {
                res.push_back(std::move(tmp));
                tmp = "";
            }
            tmp.push_back(s[i]);
        }
        if(tmp.size()) {
            while(tmp.size() < k) {
                tmp.push_back(fill);
            }
            res.push_back(std::move(tmp));
        }

        return res;
    }
};
