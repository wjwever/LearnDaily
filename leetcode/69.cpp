/*************************************************************************
    > File Name: leetcode/69.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年06月20日 星期五 10时33分54秒
 ************************************************************************/
class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = x;
        while(left <= right) {
            int mid = (left + right) / 2;
            if (int64_t (mid) * mid  > x ) {
                right = mid - 1;
            } else if (mid * mid == x) {
                return mid;
            } else {
                left = mid + 1;
            }
        }
        return left - 1;
    }
};
