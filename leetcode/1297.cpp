/*************************************************************************
    > File Name: leetcode/1297.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月21日 星期一 14时51分18秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        // dict < maxLetters, ++right
        std::unordered_map<string, int> res;
        std::unordered_map<char, int> cnt;
        int left = 0, right = 0;
        for (; right < s.size(); ++right) {
            ++cnt[s[right]];
            while(right - left + 1 >= minSize) {
                auto sz = right-left + 1;
                //std::cout << left << "\t" << right << "\t" << cnt.size() << std::endl;
                if (sz <= maxSize and cnt.size() <= maxLetters) {
                    auto str = s.substr(left, sz);
                    //std::cout << "target:" << str << std::endl;
                    ++res[str];
                }
                char c = s[left++];
                if (--cnt[c] == 0) {
                    cnt.erase(c);
                }
            }
        }

        int max_cnt = 0;
        for (auto &[k, v] : res) {
            max_cnt = max(max_cnt, v);
            //std::cout << k << "\t" << v << std::endl;
        }
        return max_cnt;
    }

};
