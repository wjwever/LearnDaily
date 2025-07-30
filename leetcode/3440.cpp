/*************************************************************************
    > File Name: leetcode/3440.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月12日 星期六 09时47分23秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}
class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> gaps_left(n, 0), gaps_right(n, 0);
        for (int i = 0; i < startTime.size(); ++i) {
            if (i == 0) {
                gaps_left[i] = startTime[0]; 
            } else {
                gaps_left[i] = max (gaps_left[i - 1], startTime[i] - endTime[i-1]);
            }
        }
        #if 0
        std::cout << "gap_left:";
        for (auto g : gaps_left) {
            std::cout << g << " ";
        }
        std::cout << "\n";
        #endif
        for (int i = startTime.size() - 1; i >= 0; --i) {
            if (i == startTime.size() - 1) {
                gaps_right[i] = eventTime - endTime[i];
            } else {
                gaps_right[i] = max(gaps_right[i + 1], startTime[i + 1] - endTime[i]);
            }
        }
        #if 0
        std::cout << "gap_right:";
        for (auto g : gaps_right) {
            std::cout << g << " ";
        }
        std::cout << "\n";
        #endif

        int max_res = 0;
        for (int i = 0; i < startTime.size(); ++i) {
            int pre = startTime[i] - (i == 0 ? 0 : endTime[i - 1]);
            int next = (i == startTime.size() - 1 ? eventTime : startTime[i + 1]) - endTime[i];

            int res = pre + next;
            if (
                (i > 0 and gaps_left[i - 1] >= endTime[i] - startTime[i])  || 
                (i < startTime.size() - 1  and gaps_right[i + 1] >= endTime[i] - startTime[i])
             ) {
                res += endTime[i] - startTime[i];
            }
            max_res = max(max_res, res);
            //std::cout << i << "\t" << pre << "\t" << next  << "\t" << res << std::endl;
        }
        return max_res;
    }
};
