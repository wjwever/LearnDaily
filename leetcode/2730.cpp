/*************************************************************************
    > File Name: leetcode/2730.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月25日 星期五 21时14分09秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int left = 0;
        int max_len = 1;
        int cnt = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i-1]) {
                ++cnt;
            }
            while(cnt > 1) {
               if (s[left] == s[left+1]) {
                --cnt;
               }
               ++left;
            }
            max_len = max(max_len, i - left + 1);
        }
        return max_len;
    }
};
