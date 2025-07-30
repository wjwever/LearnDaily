/*************************************************************************
    > File Name: leetcode/1208.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月23日 星期三 16时52分47秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int cur_cost = 0;
        int left = 0;
        int max_len = 0;
        for (int i = 0; i < s.size(); ++i) {
            cur_cost += abs(s[i] - t[i]);
            while(cur_cost > maxCost) {
                cur_cost -= abs(s[left] - t[left]);
                ++left;
            }
            max_len = max(max_len, i - left + 1);
        }
        return max_len;
    }
};
