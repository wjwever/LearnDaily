class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0; 
        int maxValueInRange = 0;
        for (int i = prices.size() - 1; i >= 0; --i) {
            if (prices[i] > maxValueInRange ) {
                maxValueInRange = prices[i];
            }
            maxProfit = max(maxProfit, maxValueInRange - prices[i]);
        }
        return maxProfit;
    }
};
