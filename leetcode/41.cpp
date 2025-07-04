class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (auto& d : nums){
            if (d <= 0) {
                d = n + 1;
            }
        }
        for (auto d :nums) {
            d = abs(d); 
            std::cout << d << std::endl;
            if (d <= n) {
                nums[d - 1] = -abs(nums[d - 1]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }
        return n + 1;
    }
};
