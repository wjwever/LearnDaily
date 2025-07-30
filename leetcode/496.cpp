/*************************************************************************
    > File Name: leetcode/496.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月10日 星期四 16时38分00秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //维护一个单调递减的栈，vector
        std::map<int, int> book;
        std::vector<int> vec;
        int N = nums2.size();
        for (int i = N - 1; i >= 0; --i) {
            while(vec.size() and vec.back() < nums2[i]) {
                vec.pop_back();
            }
            if (vec.size() > 0) {
                book[nums2[i]] = vec.back();
            } else {
                book[nums2[i]] = -1;
            }
            vec.push_back(nums2[i]);
        }
        /*
        for (auto&[k, v] : book) {
            std::cout << k << " " << v << std::endl;
        }
        */
        vector<int> res;
        for (auto &n : nums1) {
            res.push_back(book[n]);
        }
        return res;
    }
};
