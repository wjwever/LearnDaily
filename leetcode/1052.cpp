/*************************************************************************
    > File Name: leetcode/1052.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月21日 星期一 10时50分02秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int base = 0;
        for (int i = 0; i < customers.size(); ++i) {
            if (grumpy[i] == 0) {
                base += customers[i] - grumpy[i];
            }
        }
        //std::cout << "base:" << base << std::endl;

        int max_res = 0;
        for (int i = 0; i < customers.size(); ++i) {
            if (grumpy[i] != 0)  {
                base += customers[i];
            }
            max_res = max(max_res, base);
            //std::cout << i << "\t" << max_res << std::endl;
            if (i < minutes - 1) {
                continue;
            }
            if (grumpy[i - minutes + 1] != 0)  {
                base -= customers[i -minutes + 1];
            }
        }
        return max_res;
    }
};
