class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> left(len, 1);
        vector<int> right(len, 1);
        std::cout << 1 << std::endl;

        for (int i = 1; i < nums.size(); ++i) {
            left[i] = left[i - 1] * nums[i - 1];
        }
        std::cout << 2 << std::endl;

        for (int i = nums.size() - 2; i >= 0; --i) {
            right[i] = right[i + 1] * nums[i + 1];
        }
        std::cout << 3 << std::endl;

        vector<int> res(len, 1);
        for (int i = 0; i < len; ++i) {
            res[i] = left[i] * right[i];
        }
        std::cout << 4 << std::endl;
        return res;
    }
};
