/*************************************************************************
    > File Name: leetcode/2269.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月15日 星期二 22时00分26秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}


class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);   // num 十进制表示字符串
        int n = s.size();
        int res = 0;
        for (int i = 0; i <= n - k; ++i) {
            // 枚举所有长度为 k 的子串
            int tmp = stoi(s.substr(i, k));
            if (tmp && num % tmp == 0) {
                ++res;
            }
        }
        return res;
    }
};

