/*************************************************************************
    > File Name: leetcode/1652.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月21日 星期一 14时20分48秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        if (k == 0) {
            return vector<int>(code.size(), 0);
        }
        int len = code.size();
        int w = abs(k);
        int sum = 0;
        vector<int> ret ;
        int left = 1;
        if (k < 0) {
            left = (len + k) % len;
        }
        int right = left;
        for (int i = 0; i < w - 1; ++i) {
            sum += code[right++  % len];
        }
        std::cout << "sum1, " << sum << std::endl;
        for (int i = 0; i < len; ++i) {
            sum += code[right++ % len];
            ret.push_back(sum);
            sum -= code[left++ % len];
        }
        return ret;
    }
};
