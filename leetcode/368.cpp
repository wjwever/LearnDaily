/*************************************************************************
    > File Name: leetcode/368.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月09日 星期三 15时28分10秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}
class Solution {
public:
    vector<int> res;
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort (nums.begin(), nums.end()); 

        vector<int> dp(nums.size(), 1);
        vector<int> pre(nums.size(), -1);

        int max_i = 0;
        for(int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0) {
                   if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    pre[i] = j;
                   }
                }
                if (dp[i] > dp[max_i]) {
                    max_i = i;
                }
                //std::cout << nums[i] << " " << dp[i] << " " <<  max_i << std::endl ;
            }
        }
        //std::cout << max_i << " " << dp[max_i] << std::endl;
        vector<int> res;
        while(max_i >= 0) {
            //std::cout << "path:" << max_i << "->" <<  pre[max_i] << std::endl;
            res.push_back(nums[max_i]);
            max_i = pre[max_i];
        }
        return res;
    }

};
