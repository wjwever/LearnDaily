/*************************************************************************
    > File Name: leetcode/67.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年06月20日 星期五 21时19分28秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
       int carry = 0;
       std::string res;
       std::reverse(a.begin(), a.end());
       std::reverse(b.begin(), b.end());
       for ( int i =0; i < max(a.size(), b.size()); ++i) {
            int x = i >= a.size() ? 0 : a[i] - '0';
            int y = i >= b.size() ? 0 : b[i] - '0';
            res.push_back('0' + (x + y + carry) % 2);
            carry = (x + y + carry) / 2;
       }
       if (carry) {
        res.push_back('1');
       }
       std::reverse(res.begin(), res.end());
       return res;
    }
};

int main()
{
    return 0;
}

