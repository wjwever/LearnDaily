/*************************************************************************
    > File Name: 1356.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月28日 星期一 16时51分16秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        auto cnt = [](int x) {
            int cnt = 0;
            while(x) {
                cnt += x & 1;
                x >>= 1;
            }
            return cnt;
        };
        sort (arr.begin(), arr.end(), [&](int x, int y) {
            if (cnt(x) < cnt(y)) {
                return true;
            } else if ( cnt(x) == cnt(y) and x < y) {
                return true;
            }
            return false;
        });
        return arr;
    }
};
