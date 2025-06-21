/*************************************************************************
    > File Name: leetcode/191.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年06月20日 星期五 21时38分26秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingWeight(int n) {
        uint t = n;
        int num = 0;
        while(t) {
            if (t % 2) {
                num += 1;
            }
            t /= 2;
        }
        return num;
    }
};

int main()
{
    return 0;
}

