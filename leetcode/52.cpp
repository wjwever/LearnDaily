/*************************************************************************
    > File Name: leetcode/52.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年06月20日 星期五 21时09分21秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int count = 0;
    set<int> col;
    set<int> add; // for x + y
    set<int> minus; // for x -y
    int totalNQueens(int n) {
        dfs(0, n);
        return count;
    }
    void dfs(int step, int n) {
        //std::cout << step << " " << n << std::endl;
        if (step == n) {
            count ++;
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (col.count(i) == 0 and add.count(step + i) == 0 and minus.count(step - i) == 0) {
                col.insert(i);
                add.insert(step + i);
                minus.insert(step - i);
                dfs(step + 1, n);
                col.erase(i);
                add.erase(step + i);
                minus.erase(step - i);
            }
        }
    }
};

int main()
{
    return 0;
}

