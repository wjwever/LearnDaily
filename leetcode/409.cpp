/*************************************************************************
    > File Name: leetcode/409.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月09日 星期三 16时37分21秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}
class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> count;
        for (auto c: s) {
            ++count[c];
        }    
        int res = 0;
        for (auto &[first, second]: count) {
            res += 2 * (second / 2);
        }
        return min(int(s.size()), res +1);
    }
};
