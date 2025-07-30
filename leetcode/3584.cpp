/*************************************************************************
    > File Name: leetcode/3584.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月18日 星期五 21时57分05秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}
class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        long long res = LLONG_MIN;
        long long max_pos = INT_MIN, min_neg = INT_MAX; 

        int d = m -1 ;
        for (int i = d; i < nums.size(); ++i) {
            if (nums[i-d] > max_pos) {
                max_pos = nums[i-d];
            } 
            if (nums[i-d] < min_neg) {
                min_neg = nums[i-d]; 
            }
            if (max_pos != INT_MIN) {
                res = max(res, nums[i] * max_pos);
            }
            if (min_neg != INT_MAX) {
                res = max(res, nums[i] * min_neg);
            }
            //std::cout << max_pos << "\t" << min_neg << "\t" << res << std::endl;
       }

       return res;
    }
};
