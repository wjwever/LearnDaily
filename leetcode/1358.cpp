/*************************************************************************
    > File Name: leetcode/1358.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月27日 星期日 10时03分49秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution {
public:
    int numberOfSubstrings(string s) {
        std::unordered_map<char, int> cnt;
        int ans = 0;
        int left = 0;
        for (int i = 0; i < s.size(); ++i) {
            ++cnt[s[i]];
            while(cnt.size() >= 3) {
                --cnt[s[left]];
                if (cnt[s[left]] == 0) {
                    cnt.erase(s[left]);
                }
                ++left;
            }
            //std::cout << left << "->" << i << std::endl;
            ans += left;
        }
        return ans;
    }
};
