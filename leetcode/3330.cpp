/*************************************************************************
    > File Name: leetcode/3330.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月14日 星期一 18时11分24秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}


class Solution {
public:
    int possibleStringCount(string word) {
        int num_equal = 0;
        int res = 0;
        int type = 0;
        for (int i = 0; i < word.size(); ++i) {
           if (i == 0 or word[i] == word[i-1]) {
                num_equal ++;
           } else {
                if (num_equal > 1) {
                    res += num_equal;
                    ++type;
                }
                num_equal = 1;
           }
           //std::cout << i << "\t" << num_equal << "\n";
        }
        if (num_equal > 1) {
            res += num_equal;
            ++type;
        }

        if (res == 0) {
            return 1;
        } else {
            return res - type + 1;
        }
    }
};
