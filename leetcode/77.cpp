/*************************************************************************
    > File Name: leetcode/77.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年06月20日 星期五 14时28分31秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> book;
    vector<vector<int>> combine(int n, int k) {
        book.resize(n + 1, 0);
        std::vector<int> vec;
        dfs(1, k, n, vec);
        return res;
    }
    void dfs(int step, int k, int n, vector<int>& vec) {
        if (vec.size() >= k) {
            res.push_back(vec);
            return;
        }
        for (int i = step; i <= n; ++i) {
            if (book[i] == 0) {
                book[i] = 1;
                vec.push_back(i);
                dfs(i + 1, k, n, vec);
                book[i] = 0;
                vec.pop_back();
            }
        }
    }
};

int main()
{
    return 0;
}

