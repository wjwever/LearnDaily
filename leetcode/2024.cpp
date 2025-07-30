/*************************************************************************
    > File Name: leetcode/2024.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月24日 星期四 22时16分41秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        // max true
        int max_len = 0;
        int cnt_t = 0;
        int left = 0;
        auto func = [&](char T) {
            left = 0;
            cnt_t = 0;
            for (int i = 0; i < answerKey.size(); ++i) {
                if (answerKey[i] == T) {
                    ++cnt_t;
                }
                while (cnt_t > k) {
                    auto c = answerKey[left++];
                    if (c == T) {
                        --cnt_t;
                    }
                }
                max_len = max(max_len, i - left + 1);
            }
        };
        func('T');
        func('F');
        return max_len;
    }
};
