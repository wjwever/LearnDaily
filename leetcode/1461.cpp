/*************************************************************************
    > File Name: leetcode/1461.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月22日 星期二 11时42分07秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        std::set<std::string> cnt;
        std::string tmp;
        int num = 1 << k;
        for (int i = 0; i < s.size(); ++i) {
            tmp += s[i];
            if (i < k - 1) {
                continue;
            }
            cnt.insert(tmp);
            tmp = tmp.substr(1);
            if (cnt.size() >= num) {
                return true;
            }
        }
        return cnt.size() >= num ;
    }
};
