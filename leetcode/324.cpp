/*************************************************************************
    > File Name: leetcode/324.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月09日 星期三 14时05分03秒
 ************************************************************************/
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        int mid = n / 2;
        auto cmp = [&](int a, int b){
            return a > b;
        };
        sort(nums.begin(), nums.end(), cmp);
        vector<int> right(nums.begin(), nums.begin() + mid);
        std::vector<int> left(nums.begin() + mid, nums.end());
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(i % 2 == 0){
                ans.push_back(left[i / 2]);
            }else{
                ans.push_back(right[i / 2]);
            }
        }
        nums = ans;
    }
};
