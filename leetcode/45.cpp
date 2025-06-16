class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1e6);
        dp[n-1] = 0;
        for (int i = n-2 ; i >=0; --i) {
            for (int k = min(n-1, i + nums[i]); k > i; --k) {
                dp[i] = min(1 + dp[k], dp[i]);
            }
            //std::cout << i << " " << dp[i] << std::endl;
        }
        return dp[0];
    }
};
