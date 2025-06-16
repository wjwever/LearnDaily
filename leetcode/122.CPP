class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp[n][1] = max(dp[k>=n][0] + prices[k] - prices[n])
        // dp[n][0] = max(-prices[k] + dp[k>=n][k])

        int numPrices = prices.size();
        std::vector<std::vector<int>>  dp;
        dp.resize(numPrices, std::vector<int>(2, -1e6));

        dp[numPrices-1][0] = 0;
        dp[numPrices-1][1] = -prices[numPrices-1];
        for (int k = numPrices-2; k >= 0; --k) {
            for (int m = k ; m < numPrices; ++m) {
                dp[k][1] = max(dp[m][0] + prices[m] - prices[k], dp[k][1]);
                dp[k][0] = max(dp[m][0], dp[k][0]);
                dp[k][0] = max(dp[m][1], dp[k][0]);
            }
            std::cout << prices[k] << " " << dp[k][0] << " " << dp[k][1] << std::endl;
        }
        return  max(dp[0][0], dp[0][1]);
    }
};
