/*************************************************************************
    > File Name: leetcode/3201.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月16日 星期三 11时22分18秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}
class Solution {
public:
    int maximumLength(vector<int>& nums) {
       int len = nums.size();
       int even_num = 0;
       // even
       for (auto n : nums) {
            if (n % 2 == 0) {
                ++even_num;
            }
       }
       // odd
       int odd_num = nums.size() - even_num;
       int res = max(odd_num, even_num);

       //
       vector<vector<int>> dp (len, vector<int>(2, 0));
       ++dp[0][nums[0] % 2];

       //std::cout << dp[0][0] << '\t' << dp[0][1] << "\n";
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] % 2 == 1) {
                dp[i][1] = max(dp[i-1][1], 1 + dp[i-1][0]);
            } else {
                dp[i][0] = max(dp[i-1][0], 1 + dp[i-1][1]);
            }
            //std::cout << dp[i][0] << '\t' << dp[i][1] << "\n";
        }
        return max(res, max(dp.back()[0], dp.back()[1]));
    }
};
