class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0;
        int sum = 0;
        int min_ = INT_MAX;
        while(true) {
            if (sum < target) {
                if (right < nums.size()) {
                    sum += nums[right++];
                } else {
                    break;
                }
            } else {
                min_ = min(min_, right - left);
                if (left < right) {
                    sum -= nums[left++];
                } else {
                    break;
                }
            }
            std::cout << left << " " << right << " " << sum << " " << min_ << std::endl;
        }       
        return min_ == INT_MAX ? 0 : min_;
    }
};
