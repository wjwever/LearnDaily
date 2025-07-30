/*************************************************************************
    > File Name: leetcode/3325.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月27日 星期日 10时18分37秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        std::map<char, int> cnt;

        auto check = [&]() {
            for (auto& [key, val] : cnt) {
                if (val >= k) {
                    return true;
                }
            }
            return false;
        };

        int left = 0;
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            ++cnt[s[i]];
            while(check()) {
                auto c = s[left++];
                --cnt[c];
            }
            ans += left;
        }
        return ans;
    }
};
