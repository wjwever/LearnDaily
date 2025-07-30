/*************************************************************************
    > File Name: leetcode/2001.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月17日 星期四 14时22分52秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        long long ans = 0;
        unordered_map<double, int> map;
        for(int i = 0; i < rectangles.size(); i++){
            double v = rectangles[i][0] * 1.0 / rectangles[i][1];
            ans += map[v];
            map[v]++;
        }
        return ans;
    }
};
