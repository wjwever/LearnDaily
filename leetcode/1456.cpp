/*************************************************************************
    > File Name: LearnDaily/leetcode/1456.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月19日 星期六 20时42分02秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}
class Solution {
public:
    int maxVowels(string s, int k) {
        std::set<char> yuyin = {'a', 'e', 'i', 'o', 'u'};
        int cnt = 0;
        int max_res = 0;
        for (int i = 0; i < k -1; ++i) {
            if (yuyin.count(s[i])) {
                ++cnt;
            }
        }
        for (int i = k-1; i < s.size(); ++i) {
            if (yuyin.count(s[i])) {
                ++cnt;
            }
            max_res = max(max_res, cnt);
            if (yuyin.count(s[i - k + 1])) {
                --cnt;
            }
        }
        return max_res;
    }
};
