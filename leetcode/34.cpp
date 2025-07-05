class Solution {
public:
    int find1st(vector<int>& nums, int target) {
        if (nums.empty()) {
            return -1;
        }
        int start = 0, end  = nums.size() - 1;
        std::cout << start << " " << end << std::endl;
        while(start <= end) {
            std::cout << start << " " << end << std::endl;
            int mid = (start + end) / 2;
            if (nums[mid] >= target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return  start < nums.size() and nums[start] == target ? start : -1;
    }

    int findlast(vector<int>& nums, int target) {
        if (nums.empty()) {
            return -1;
        }
        int start = 0, end  = nums.size() - 1;
        while(start <= end) {
            std::cout << start << " " << end << std::endl;
            int mid = (start + end) / 2;
            if (nums[mid] <= target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return  end >= 0 and nums[end] == target ? end: -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, 0) ;
        res[0] = find1st(nums, target);
        std::cout << res[0] << "\n";

        res[1] = findlast(nums, target);
        std::cout << res[1] << "\n";
        return res;
    }
};
