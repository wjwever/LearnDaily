/*************************************************************************
    > File Name: 3226.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月28日 星期一 16时59分20秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution {
public:
    int minChanges(int n, int k) {
       return (n & k) == k ? __builtin_popcount(n ^  k) : -1; 
    }
};
