class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int, int> dict;
        std::vector<int> res;
        for (int i = 0 ; i < nums.size(); ++i) {
            if (dict.count(target-nums[i])) {
                res.push_back(dict[target-nums[i]]);
                res.push_back(i);
                break;
            }
            dict[nums[i]] = i;
        }
        return res;
    }
};
