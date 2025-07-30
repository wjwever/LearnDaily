/*************************************************************************
    > File Name: leetcode/482.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月11日 星期五 12时51分19秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        std::string new_res;
        int i = 0;
        int tmp = k;

        int group = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] != '-') {
                std::cout << s[i] << std::endl;
                if (new_res.size() > 0 and group == k) {
                    new_res.push_back('-');
                    group = 0;
                }
                new_res.push_back(std::toupper(s[i]));
                ++group;
            }
        }

        std::reverse(new_res.begin(), new_res.end());
        
        return new_res;
    }
};
