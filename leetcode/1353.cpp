/*************************************************************************
    > File Name: leetcode/1353.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月14日 星期一 22时21分48秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        // 按照开始时间 结束时间进行排序 
        sort (events.begin(), events.end());

        int max_day = 1;  
        for (auto& event : events) {
            max_day = max(max_day, event[1]);
        }

        int res = 0;
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        int n = 0;
        std::cout << "max_day:" << max_day << std::endl;
        for (int i = 1; i <= max_day; ++i) {
            // day i开始的会议入队列
            while(n < events.size() and events[n][0] == i) {
                pq.push(events[n][1]);
                n++;
            }
            // day i结束的会议出列
            while (pq.size()) {
                if (pq.top() < i) {
                    pq.pop();
                } else {
                    break;
                }
            }
            // 选择最早结束的会议
            if (pq.size()) {
                std::cout << "select:" << i << "\t" << pq.top() << std::endl;
                pq.pop();
                res += 1;
            }
        }
        return res;
    }
};
