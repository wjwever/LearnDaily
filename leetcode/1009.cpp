/*************************************************************************
    > File Name: 1020.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月30日 星期三 21时53分27秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}
class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        int len = __lg(n)+1;
        unsigned int mask = (1U << len) - 1;
        return mask - n;
    }
};

