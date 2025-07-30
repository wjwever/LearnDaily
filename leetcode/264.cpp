/*************************************************************************
    > File Name: leetcode/264.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月17日 星期四 17时08分13秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        std::map<int, int> book;
        long long res = 0;
        ++book[nums[0]];
        for (int i = 1; i < nums.size(); ++i) {
            res += (i - book[nums[i] -i]);
            ++book[nums[i] -i];
        }
        return res;
    }
};
