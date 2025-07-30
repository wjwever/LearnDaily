/*************************************************************************
    > File Name: leetcode/2260.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月17日 星期四 14时44分02秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}
class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        std::unordered_map<int, int> pos; 
        int res = -1;
        for (int i = 0; i < cards.size(); ++i) {
            if (pos.count(cards[i])) {
                if (res == -1) {
                    res = i - pos[cards[i]] + 1;
                } else {
                    res = min(res, i - pos[cards[i]] + 1);
                }
            }
            pos[cards[i]] = i;
        }
        return res;
    }
};
