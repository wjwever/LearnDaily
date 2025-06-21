class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int beg = 0;
        vector<string> res;
        if (nums.empty()) {
            return res;
        }
        for (int i = 1; i < nums.size(); ++i) {
            if ( nums[i] != nums[i - 1] + 1) {
                if (i - beg == 1) {
                    res.push_back(std::to_string(nums[beg]));
                } else {
                    res.push_back(std::to_string(nums[beg]) + "->" + std::to_string(nums[i - 1]));
                }
                beg = i;
            }
        }
        if (beg == nums.size() - 1) {
            res.push_back(std::to_string(nums[beg]));
        } else {
            res.push_back(std::to_string(nums[beg]) + "->" + std::to_string(nums.back()));
        }
        return res;
    }
};


class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        int i = 0;
        int n = nums.size();
        while (i < n) {
            int low = i;
            i++;
            while (i < n && nums[i] == nums[i - 1] + 1) {
                i++;
            }
            int high = i - 1;
            string temp = to_string(nums[low]);
            if (low < high) {
                temp.append("->");
                temp.append(to_string(nums[high]));
            }
            ret.push_back(move(temp));
        }
        return ret;
    }
};

作者：力扣官方题解
链接：https://leetcode.cn/problems/summary-ranges/solutions/553645/hui-zong-qu-jian-by-leetcode-solution-6zrs/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
