/*************************************************************************
    > File Name: leetcode/2904.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月26日 星期六 16时28分42秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string final_res = "";
        int left = 0;
        int num1 = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1') {
                ++num1;
            }
            while(num1 >= k) {
                if (num1 == k) {
                    auto tmp = s.substr(left, i - left + 1);
                    if (final_res == "" || tmp.size() < final_res.size() ||(tmp.size() == final_res.size() and tmp < final_res)) {
                        final_res = tmp;
                    }
                    //std::cout << "tmp:" << tmp << std::endl;
                }
                auto c = s[left++];
                if (c == '1') --num1;
            }
        }
        return final_res;
    }
};
