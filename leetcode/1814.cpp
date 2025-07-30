/*************************************************************************
    > File Name: leetcode/1814.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月18日 星期五 20时39分26秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}
class Solution {
public:
    int rev(int n) {
        int res = 0 ;
        while(n) {
            int tail = n % 10;
            res = res * 10 + tail;
            n /= 10;
        }
        return res;
    }

    std::map<int, int> book;
    const int MOD = 1000000007;

    int countNicePairs(vector<int>& nums) {
        int res = 0;
        for (auto n : nums) {
            auto key = n - rev(n);
            //std::cout << n << "\t" << rev(n) << "\t" << n - rev(n) << "\t" << book[key] << std::endl;
            res = (res + book[key]) % MOD;
            ++book[key]  ;
        }
        return res;
    }
};
