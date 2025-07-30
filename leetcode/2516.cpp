/*************************************************************************
    > File Name: leetcode/2516.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月25日 星期五 20时57分57秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution {
public:
    int takeCharacters(string s, int k) {
        std::map<char, int> cnt = {{'a',-k},{'b',-k}, {'c',-k}};
        for (auto c : s) ++cnt[c];
        for (auto& [key, val] : cnt) {
            if (val < 0) {
                return -1;
            }
        }
        std::cout << "1\n";

        std::map<char, int> test;
        int max_len = 0;
        int left = 0;
        for (int i = 0; i < s.size(); ++i) {
            ++test[s[i]];
            while(test[s[i]] > cnt[s[i]]) {
                //std::cout << left << "\n";
                auto c = s[left++];
                --test[c];
            }
            max_len = max(max_len, i - left + 1);
        }
        return s.size() - max_len;
    }
};
