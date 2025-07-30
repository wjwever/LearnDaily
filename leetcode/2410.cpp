/*************************************************************************
    > File Name: leetcode/2410.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月13日 星期日 08时16分11秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort (players.begin(), players.end());
        sort (trainers.begin(), trainers.end());

        int id1 = 0, id2 = 0;
        int cnt = 0;
        while (id1 < players.size()) {
            if (id2 >= trainers.size()) {
                break;
            }
            if (players[id1] <= trainers[id2]) {
                ++cnt;
                ++id1;
                ++id2;
            } else {
                ++id2;
            }
        }
        return cnt;
    }
};
