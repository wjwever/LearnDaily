/*************************************************************************
    > File Name: leetcode/207.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年06月20日 星期五 12时38分42秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges (numCourses, vector<int>());
        vector<int> in_degrees(numCourses, 0);

        for (const auto & pre : prerequisites) {
            int from = pre[0];
            int to = pre[1];
            in_degrees[to] ++;
            edges[from].push_back(to);
        }

        queue<int> Q;
        for (int i = 0; i < numCourses; ++i) {
            if (in_degrees[i] == 0) {
                Q.push(i);
            }
        }

        // check能有多少个indegree为0的节点
        int cnt = 0;
        while (Q.size() > 0) {
            int from = Q.front();
            Q.pop();
            ++cnt;
            for (auto to : edges[from]) {
                --in_degrees[to];
                if (in_degrees[to] == 0) {
                    Q.push(to);
                }
            }
        }

        std::cout << cnt << " " << numCourses << "\n";
        return cnt == numCourses;
    }
};

int main()
{
    return 0;
}
