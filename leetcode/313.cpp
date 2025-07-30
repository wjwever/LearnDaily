/*************************************************************************
    > File Name: leetcode/313.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月09日 星期三 11时17分34秒
 ************************************************************************/
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> Q;
        Q.push(1);

        int last = -1;
        for (int i =0; ; ) {
            int cur = Q.top();
            Q.pop();

            if (last != cur) {
                ++i;
                last = cur;
            } 

            if (i == n) {
                return cur;
            }
            for (auto p : primes) {
                if ((long long)cur * p <= INT_MAX) {
                    Q.push(cur * p);
                }
            }
        }
        return -1;
    }
};
