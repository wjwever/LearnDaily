/*************************************************************************
    > File Name: leetcode/2799.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月27日 星期日 10时45分42秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
       map<int,int> cnt;
       for (auto n : nums) ++cnt[n];
       int cnt_num = cnt.size();
       cnt.clear();
       int ans = 0, left = 0;
       for (int i = 0; i < nums.size(); ++i) {
            ++cnt[nums[i]];
            while(cnt.size() >= cnt_num) {
                auto n = nums[left++];
                --cnt[n];
                if (cnt[n] == 0) cnt.erase(n);
            }
            ans += left;
       }
       return ans;
    }
};
