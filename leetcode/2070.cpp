/*************************************************************************
    > File Name: leetcode/2070.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月16日 星期三 15时17分20秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}


class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort (items.begin(), items.end());

        int cur_max_beau = 0;
        std::map<int, int> book;
        for (auto& item : items) {
            cur_max_beau = max(cur_max_beau, item[1]);
            book[item[0]] = max(cur_max_beau, book[item[0]]);
        }

        std::vector<int> res;
        for (auto q : queries) {
            auto it = book.upper_bound(q);
            if (it != book.begin()) {
                --it;
                res.push_back(it->second);
            }  else {
                res.push_back(0);
            }
        }
        return res;
    }
};
