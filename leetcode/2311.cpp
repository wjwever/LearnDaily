/*************************************************************************
    > File Name: leetcode/2311.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月16日 星期三 14时41分54秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int num_zero = 0;
        for (auto c : s) {
            if (c == '0') {
                ++num_zero;
            }
        }

        int64_t res = 0;
        int i = s.size() - 1;
        for (; i >= 0; --i) {
            if (s[i] != '1') {
                continue;
            }
            //std::cout << i << '\t' << res +(1 << (s.size() -i - 1)) << '\t' << k <<std::endl;
            if (s.size() -i -1 >= 31) {
                break;
            }
            if (res + (int64_t(1) << (s.size() -i - 1)) > k) {
                break;
            }
            res += 1 << s.size() -i - 1;
            num_zero += 1;
            //std::cout << num_zero << '\t' << res << std::endl;
        }
        //std::cout << i << std::endl;
        return num_zero;
    }
};
