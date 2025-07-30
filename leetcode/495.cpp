/*************************************************************************
    > File Name: leetcode/495.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月10日 星期四 22时01分52秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
       int res = 0;
       for (int i =0; i < timeSeries.size(); ++i) {
            res += duration;
            if ( i > 0) {
                int time_gap = timeSeries[i] - timeSeries[i - 1];
                if (time_gap < duration) {
                    res -= (duration - time_gap);
                }
            }
       } 
       return res;
    }
};
