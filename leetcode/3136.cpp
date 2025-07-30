/*************************************************************************
    > File Name: leetcode/3136.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月15日 星期二 11时41分01秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution {
public:
    bool isValid(string word) {
        bool contain_yuanyin = false;
        bool contain_fuyin = false;
        bool contain_digit = false;

        std::set<char> yuanyin = {'a', 'e','i', 'o', 'u'};
        for (auto c : word) {
            if (!isalnum(c)) {
                return false;
            }
            if (isalpha(c)) {
                if (yuanyin.count(tolower(c))) {
                    contain_yuanyin = true;
                }
                else {
                    contain_fuyin = true;
                }
            }
            if (isdigit(c)) {
                contain_digit = true;
            }
        }
        return contain_fuyin and contain_yuanyin and word.size() >=3;
    }
};
