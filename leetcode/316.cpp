/*************************************************************************
    > File Name: leetcode/316.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月09日 星期三 13时55分04秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}
class Solution {
public:
    string removeDuplicateLetters(string s) {
        std::map<char, int> count;
        std::set<char> used;
        for (auto c : s) ++count[c];

        std::string res; 
        for (auto c : s) {
            --count[c];
            if (used.count(c)) {
                continue;
            }
            while(res.size() > 0 and res.back() > c) {
                char t = res.back();
                if (count[t] == 0) {
                    break;
                } else {
                    res.pop_back();
                    used.erase(t);
                }
            }
            res.push_back(c);
            used.insert(c);
            std::cout << c << " " << res <<std::endl;
        }
        return res;
    }
};
