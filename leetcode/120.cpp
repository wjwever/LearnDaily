/*************************************************************************
    > File Name: 120.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年06月19日 星期四 15时20分01秒
 ************************************************************************/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int height = triangle.size();
        vector<vector<int>> dp;
        dp.resize(height);
        for (int h = 0; h < height; ++h) {
             if (h == 0) {
                dp[0].push_back(triangle[h][0]);
                continue;
             } 
            for (int i =0;  i < triangle[h].size(); ++i) {
                int val = triangle[h][i];
                if (i == 0) {
                    val += dp[h-1][0];
                } else if ( i == triangle[h].size() - 1)  {
                    val += dp[h-1].back();
                } else {
                    val += min(dp[h-1][i], dp[h-1][i-1]);
                }
                dp[h].push_back(val);
            }
            for (auto i = 0; i < dp[h].size(); ++i) {
                std::cout << dp[h][i] << " ";
            }
            std::cout << "\n";
        }
        auto it = std::min_element(dp.back().begin(), dp.back().end());
        return *it;
    }
};
