/*************************************************************************
    > File Name: 2220.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月28日 星期一 16时43分10秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution {
public:
    int minBitFlips(int start, int goal) {
       int res = start ^ goal;
       int cnt = 0;
       while(res) {
            cnt += 1;
            res &= (res - 1);
       }
       return cnt;
    }
};
