/*************************************************************************
    > File Name: leetcode/315.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月09日 星期三 12时07分59秒
 ************************************************************************/
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> d(n, 0);
        for (int i = n - 1; i >=0; --i) {
            for (int t = i + 1; t < n; ++t) {
                if (nums[t] < nums[i]) {
                    ++d[i];
                }
            }
        }
        for (auto& f : d) {
            std::cout << f << " ";
        }
        return d;
    }
};
