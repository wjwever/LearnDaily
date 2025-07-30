/*************************************************************************
    > File Name: leetcode/2379.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月20日 星期日 09时26分12秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int num_w = 0;
        int left = 0;
        int min_val = INT_MAX;
        for (int i = 0; i < blocks.size(); ++i) {
            if (blocks[i] == 'W') ++num_w;

            if (i - left + 1 < k) {
                continue;
            }
            min_val = min(num_w, min_val);

            if (blocks[left++] == 'W') --num_w;
        }
        return min_val;
    }
};
