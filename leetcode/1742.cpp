/*************************************************************************
    > File Name: leetcode/1742.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月09日 星期三 10时51分04秒
 ************************************************************************/
class Solution {
public:
    int hash(int val) {
        int res = 0;
        while (val > 0) {
            res += val % 10;
            val /= 10;
        }
        return res;
    }
    int countBalls(int lowLimit, int highLimit) {
        std::map<int, int> count;
        int maxval = 0;
        for (int i = lowLimit; i <= highLimit; ++i) {
            ++count[hash(i)];
            maxval = max(maxval, count[hash(i)]);
        }
        return maxval;
    }
};

