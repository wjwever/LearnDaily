/*************************************************************************
    > File Name: leetcode/1014.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月18日 星期五 20时25分00秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int max_res = values[0];
        int ret = 0;
        for (int i =1; i < values.size(); ++i) {
            ret = max(ret, max_res + values[i] - i);
            max_res = max(max_res, values[i] + i);
        }
        return ret;
    }
};
