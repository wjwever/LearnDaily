/*************************************************************************
    > File Name: leetcode/567.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月22日 星期二 11时11分07秒
 ************************************************************************/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> book;
    vector<int> test;
    bool checkInclusion(string s1, string s2) {
        book.resize(26, 0);
        test.resize(26, 0);
        std::swap(s1, s2);
        int l2 = s2.size();
        for (int i = 0; i < l2; ++i) {
            ++book[s2[i] - 'a'];
        }
        for (int i = 0; i < s1.size(); ++i) {
            ++test[s1[i] - 'a'];
            if (i < l2 - 1) {
                continue;
            }
            if (book == test) {
                return true;
            }
            --test[s1[i- l2 + 1] - 'a'];
        }
        return false;
    }
};
