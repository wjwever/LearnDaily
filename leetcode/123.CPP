/*************************************************************************
    > File Name: leetcode/123.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年06月20日 星期五 08时15分48秒
 ************************************************************************/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int k = 2; // 交易k次
        vector<int> buy(k + 1, INT_MIN), sell(k + 1, 0);
        for (int price : prices) {
            for (int i = 1; i <= k; ++i) {
                buy[i] = max(buy[i], sell[i - 1] - price);
                sell[i] = max(sell[i], buy[i] + price);
            }
        }
        return sell[k];
    }
};
