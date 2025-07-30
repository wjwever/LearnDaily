/*************************************************************************
    > File Name: leetcode/1695.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月23日 星期三 16时24分15秒
 ************************************************************************/

#include <vector>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int max_sum = 0;
        std::map<int, int> cnt;
        int cur_sum = 0;
        int left = 0;
        for (int i = 0; i < nums.size(); ++i) {
            ++cnt[nums[i]];
            std::cout << nums[i] << " " << cnt[nums[i]] << std::endl;
            cur_sum += nums[i];
            while(cnt[nums[i]] > 1) {
                std::cout << left << "=>" << i << " " << nums[i] << " " << cnt[nums[i]] << "\n";
                int n = nums[left++];
                --cnt[n];
                cur_sum -= n;
            }
            max_sum = max(max_sum, cur_sum);
            std::cout << left << "=>" << i << "\t" << max_sum << "\n";
        }
        return max_sum;
    }
};

int main()
{
    Solution s;
    std::vector<int> data = {4751,5697,197,3468,9548,1096,1979,515,5140,2235,8351};
    std::cout << s.maximumUniqueSubarray(data) << std::endl;
    return 0;
}

