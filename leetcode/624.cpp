/*************************************************************************
    > File Name: leetcode/624.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月15日 星期二 17时41分04秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}


class Solution {
public:
    struct ele {
        int val;
        int index;
        bool operator<(const ele& rhs) const {
            return val < rhs.val or (val == rhs.val and index < rhs.index);
        }
    };

    int maxDistance(vector<vector<int>>& arrays) {
        std::set<ele> max_arr;
        std::set<ele> min_arr;
        for(int i = 0; i < arrays.size(); ++i) {
            max_arr.insert(ele{arrays[i].back(), i});
            min_arr.insert(ele{arrays[i][0], i});
        }
        #if 0
        for (auto& ele : max_arr) {
            std::cout << ele.val << "\t" << ele.index << std::endl;
        }
        for (auto& ele : min_arr) {
            std::cout << ele.val << "\t" << ele.index << std::endl;
        }
        #endif
        if (max_arr.rbegin()->index != min_arr.begin()->index) {
            return max_arr.rbegin() -> val - min_arr.begin() -> val;
        } else {
            auto it = max_arr.rbegin();
            std::advance(it, 1);
            int res1 =  it-> val - min_arr.begin() -> val;
            auto it2 = min_arr.begin();
            std::advance(it2, 1);
            int res2 = max_arr.rbegin()->val - it2 -> val;
            return max(res1, res2);
        }
    }
};

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int res = 0;
        int min_val = arrays[0][0];
        int max_val = arrays[0].back();
        for (int i = 1; i < arrays.size(); ++i) {
            res = max(res, max(max_val - arrays[i][0], arrays[i].back() - min_val));
            min_val = min(min_val, arrays[i][0]);
            max_val = max(max_val, arrays[i].back());
        }
        return res;
    }
};
