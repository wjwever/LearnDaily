/*************************************************************************
    > File Name: leetcode/3169.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月11日 星期五 17时26分49秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        auto cmp = [](const vector<int>& a, const vector<int>&b) {
            return a[0] < b[0];
        } ;

        sort (meetings.begin(), meetings.end(), cmp);

        int res = 0;
        if (meetings[0][0] > 1) res += meetings[0][0] - 1;
        int max_range = meetings[0][1];
        for (int i = 1; i < meetings.size(); ++i) {
            auto day =  max(0, meetings[i][0] - max_range - 1);
            res += day;
            if (day) {
                std::cout << "test" << meetings[i][0] << "\t" << meetings[i][1] << std::endl;
            }
            max_range = max(max_range, meetings[i][1]);
        }

        res += max(0, days - max_range);

        return res;
    }
};
