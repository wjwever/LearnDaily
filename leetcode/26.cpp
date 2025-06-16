class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int id1 = 1, id = 0;
        while (id1 < nums.size()) {
            if (nums[id1] == nums[id]) {
                id1 ++;
            } else {
                nums[++id] = nums[id1++];
            }
        }
        return id + 1;
    }
};
