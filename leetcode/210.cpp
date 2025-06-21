/*************************************************************************
    > File Name: leetcode/210.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年06月20日 星期五 13时29分57秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
       vector<int> inDegree(numCourses, 0);
       vector<vector<int>> data(numCourses);
       for (auto& vec : prerequisites) {
            data[vec[1]].push_back(vec[0]);
            inDegree[vec[0]]++;
       }

       queue<int> Q;
       for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                Q.push(i);
            }
       }
       vector<int> res;
       while(Q.size() > 0) {
        int course = Q.front();
        Q.pop();
        res.push_back(course);
        for (auto fanout : data[course]) {
            if (--inDegree[fanout] == 0) {
                Q.push(fanout);
            }
        }
       }
       if (res.size() == numCourses) {
        return res;
       } else {
        res.clear();
        return res;
       }
    }
};

int main()
{
    return 0;
}

