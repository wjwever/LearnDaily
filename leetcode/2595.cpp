/*************************************************************************
    > File Name: leetcode/2595.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月15日 星期二 18时05分46秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution {
public:
    vector<int> evenOddBit(int n) {
       int odd = 0, even = 0;
       int index = 0;
       while(n) {
            if (n & 1 == 1) {
                if (index % 2 == 0) {
                    ++even;
                } else {
                    ++odd;
                }
            }
            n = n >> 1;
            index ++;
       }
       return {even, odd};
    }
};
