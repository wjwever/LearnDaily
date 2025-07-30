/*************************************************************************
    > File Name: leetcode/2815.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月17日 星期四 14时58分00秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}
class Solution {
public:
    int get_max_bit(int n) {
        int res = 0;
        while(n) {
            res = max(res, n % 10);
            n /= 10;
        }
        return res;
    }
    int maxSum(vector<int>& nums) {
        std::map<int, int> book;
        int max_res = -1;
        for (int i = 0; i < nums.size(); ++i) {
            auto max_bit = get_max_bit(nums[i]);
            //std::cout << nums[i] << "\t" << max_bit << std::endl;
            if (book.count(max_bit)) {
                max_res = max(max_res, nums[i]  +  book[max_bit]);
            }
            if (nums[i] > book[max_bit]) {
                book[max_bit] = nums[i];
            }
        }
        return max_res;
    }
};
