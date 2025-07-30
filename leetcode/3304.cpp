/*************************************************************************
    > File Name: leetcode/3304.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月14日 星期一 12时12分43秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}
class Solution {
public:
    char kthCharacter(int k) {
        string res = "a";
        while (res.size() < k) {
            int sz = res.size();
            for (int i = 0; i < sz; ++i) {
                auto next = res[i] == 'z' ? 'a' : res[i] + 1;
                res.push_back(next);
            }
        }
        return res[k-1];
    }
};
