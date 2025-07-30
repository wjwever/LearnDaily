/*************************************************************************
    > File Name: leetcode/3090.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月22日 星期二 21时10分56秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int max_len = 0;
        int left = 0;
        std::map<char, int> cnt;
        for (int i = 0; i < s.size(); i ++) {
            ++cnt[s[i]];
            while(cnt[s[i]] > 2) {
                --cnt[s[left++]];
            }
            max_len = max(max_len, i - left + 1);
        }
        return max_len;
    }
};
