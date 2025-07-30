/*************************************************************************
    > File Name: leetcode/424.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月10日 星期四 11时39分27秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}
class Solution {
public:
    int characterReplacement(string s, int k) {
        int  len = 0;
        int left = 0, right = 0;
        std::map<char, int> cnt;
        int curMax = 0;
        while (right < s.size()) {
            ++ cnt[s[right]];
            curMax = max(curMax, cnt[s[right]]);
            while(right -left + 1 - curMax > k) {
                --cnt[s[left++]];
            }
            len = std::max(len, right - left + 1);
            ++right;
        }
        return len;
    }
};
