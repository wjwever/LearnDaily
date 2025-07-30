/*************************************************************************
    > File Name: leetcode/3110.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月15日 星期二 22时05分41秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution {
public:
    int scoreOfString(string s) {
        int sum = 0;
        for (int i = 1; i < s.size(); ++i) {
            sum += abs(s[i] - s[i-1]);
        }
        return sum;
    }
};
