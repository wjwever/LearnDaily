/*************************************************************************
    > File Name: leetcode/2080.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月15日 星期二 21时29分07秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class RangeFreqQuery {
public:
    std::map<int, vector<int>> pos;
    RangeFreqQuery(vector<int>& arr) {
       for (int i = 0;i < arr.size(); ++i) {
            pos[arr[i]].push_back(i);
       }
    }

    int query(int left, int right, int value) {
        if (pos[value].size() == 0) {
            return 0;
        }

        auto& vec = pos[value];
        // binary search
        int last = upper_bound(vec.begin() , vec.end() , right) - vec.begin();
        int first  = lower_bound(vec.begin(), vec.end() , left) - vec.begin();
        return last - first;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
