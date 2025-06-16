class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int current_count = 1;     
        int current_number = nums[0] ;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != current_number) {
                if (current_count == 1) {
                    current_number = nums[i];
                } else {
                    current_count--;
                }
            } else {
                current_count ++;
            }
        }
        return current_number;
    }
};
