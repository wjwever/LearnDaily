/*************************************************************************
    > File Name: leetcode/3340.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月15日 星期二 22时04分10秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}


class Solution {
public:
    bool isBalanced(string num) {
        int even = 0;
        int odd = 0;
        for (int i = 0; i < num.size(); ++i) {
            if (i % 2 == 1) {
                odd += num[i] - '0';
            } else {
                even += num[i] - '0';
            }
        }
        return odd == even;
    }
};
