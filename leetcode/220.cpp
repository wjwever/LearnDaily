/*************************************************************************
    > File Name: leetcode/220.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月22日 星期二 20时33分06秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int k = indexDiff;
        int t = valueDiff;
        std::set<int> book;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = book.lower_bound(max(nums[i], INT_MIN+t) -t);
            if (it != book.end() and *it <= nums[i] + t) {
                return true;
            }
            book.insert(nums[i]);
            if (i >= k) {
                book.erase(nums[i-k]);
            }
        }
        return false;
    }
};
