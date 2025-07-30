/*************************************************************************
    > File Name: 3370.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月28日 星期一 16时36分10秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution {
public:
    int smallestNumber(int n) {
       int res = 1; 
       while(res < n) {
        res = (res << 1) | 1; 
       }
       return res;
    }
};
