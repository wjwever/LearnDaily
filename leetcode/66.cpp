/*************************************************************************
    > File Name: leetcode/66.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年06月20日 星期五 08时36分33秒
 ************************************************************************/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
       int carry = 1;
       for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
            int tmp = (*it + carry )  % 10;
            carry = (*it + carry )  / 10;
            *it = tmp;
       }
       if (carry) {
            digits.insert(digits.begin(), carry);
       }
       return digits;
    }
};
