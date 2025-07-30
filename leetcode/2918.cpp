/*************************************************************************
    > File Name: leetcode/2918.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月15日 星期二 23时11分06秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long res1 = 0, res2 = 0;
        long long n1 = 0, n2 = 0;
        for (auto n : nums1) {
            res1 += n;
            if (n == 0) {
                ++n1;
            }
        }
        for (auto n : nums2) {
            res2 += n;
            if (n == 0) {
                ++n2;
            }
        }

        if (res1 + n1  < res2 + n2 and n1 == 0) {
            return -1;
        }
        if (res2 + n2 < res1 + n1 and n2 == 0) {
            return -1;
        }
        return max(res2 +n2, res1 + n1);
    }
};
