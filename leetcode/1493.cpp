/*************************************************************************
    > File Name: leetcode/1493.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月23日 星期三 16时40分21秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        std::map<int, int> cnt;
        int left = 0;
        int max_res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            ++cnt[nums[i]]; 
            while(cnt[0] > 1) {
                int n = nums[left++];
                --cnt[n];
            }
            //std::cout << left << "=>" << i <<  "\n";
            max_res = max(max_res, i - left + 1);
        }
        return max_res - 1;
    }
};
