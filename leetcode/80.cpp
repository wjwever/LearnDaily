class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int num = 0, back = 0, cur = 1;
        while(cur < nums.size()) {
            if (nums[cur] != nums[back]) {
                num = 0;
                nums[++back] = nums[cur++];
            } else {
                ++num;
                if (num < 2) {
                    nums[++back] = nums[cur];
                }
                cur ++;
            }
        }
        return back + 1; 
    }
};
