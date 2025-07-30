/*************************************************************************
    > File Name: leetcode/3202.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月17日 星期四 11时28分47秒
 ************************************************************************/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int len = nums.size();
        vector<vector<int>> dp(len, vector<int>(k, 1));

        std::cout << nums[0] << std::endl;
        for (int s = 0; s < k; ++s) {
            std::cout << dp[0][s] << "\t";
        }
        std::cout << std::endl;

        for (int i = 1; i < nums.size(); ++i) {
            for (int t = 0; t < i; ++t) {
                int mod = (nums[i] + nums[t]) % k;
                dp[i][mod] = max(dp[i][mod], 1 + dp[t][mod]);
            }
            std::cout << nums[i] << std::endl;
            for (int s = 0; s < k; ++s) {
                std::cout << dp[i][s] << "\t";
            }
            std::cout << std::endl;
        }

        int max_res = 1;
        for (auto& vec : dp) {
            for (auto& res : vec) {
                max_res = max(max_res, res);
            }
        }
        return max_res;
    }
};

int main()
{
    vector<int> res = {1,5,9,2,8};        
    Solution s;
    std::cout << s.maximumLength(res, 2) << std::endl;
    return 0;
}

