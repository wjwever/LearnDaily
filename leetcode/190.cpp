/*************************************************************************
    > File Name: leetcode/190.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年06月20日 星期五 21时32分36秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        string tmp = "";
        int num = 0;
        while(n > 0) {
            tmp.push_back('0' + n % 2);
            res = res * 2 + n % 2;
            n /= 2;
            num ++ ;
        }
        while (num < 32) {
            num ++;
            res *= 2;
        }
        //std::cout << tmp << std::endl;
        return res;
    }
};

int main()
{
    return 0;
}

