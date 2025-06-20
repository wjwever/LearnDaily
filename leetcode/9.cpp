/*************************************************************************
    > File Name: leetcode/9.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年06月20日 星期五 08时29分14秒
 ************************************************************************/


class Solution {
public:
    bool isPalindrome(int x) {
       if (x < 0) {
            return false;
       }
       long long a = 1;
       while(a * 10 < x) {
        a*= 10;
       }
       while(x > 0) {
        int left = x / a;
        int right = x % 10;
        std::cout << a << " " <<  left << ' ' << right << std::endl;
        if (left != right) {
            return false;
        }
        x %= a;
        x /= 10;
        a /= 100;
       }
       return true;
    }
};
