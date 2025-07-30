/*************************************************************************
    > File Name: leetcode/481.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月11日 星期五 12时30分58秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution {
public:
    int magicalString(int n) {
        vector<int> tmp = {1};
        int num_index = 0;
        int cur_num = 1;

        while(tmp.size() < n) {
            int num = tmp[num_index];
            while(cur_num < num) {
                tmp.push_back(tmp.back());
                ++cur_num;
            }
            if (tmp.back() == 1) {
                tmp.push_back(2);
            } else {
                tmp.push_back(1);
            }
            num_index ++;
            cur_num = 1;
        }
        int total = 0;
        int num = 0;
        for (auto& c : tmp) {
            if (num++ >= n) {
                break;
            }
            if (c == 1) {
                ++total;
            }
            //std::cout << c << " ";
        }

        return total;
    }
};
