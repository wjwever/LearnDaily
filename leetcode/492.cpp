/*************************************************************************
    > File Name: leetcode/492.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月10日 星期四 22时31分11秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}
class Solution {
public:
    vector<int> constructRectangle(int area) {
        int w = sqrt(1.0 * area);
        while (area % w) {
            --w;
        } 
        return {area/ w, w};
    }
};
