/*************************************************************************
    > File Name: 461.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月28日 星期一 16时40分16秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution {
public:
    int hammingDistance(int x, int y) {
       unsigned res = x ^ y; 
       int cnt = 0;
       while (res) {
            cnt += res & 1;
            res = res >> 1;
       }
       return cnt;
    }
};
