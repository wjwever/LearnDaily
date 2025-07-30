/*************************************************************************
    > File Name: leetcode/904.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月23日 星期三 16时59分04秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
       int win = 2; 
       int left = 0;
       int max_len = 0;
       std::map<int, int> cnt;
       for (int i = 0; i < fruits.size(); ++i) {
            ++cnt[fruits[i]];
            while(cnt.size() > win) {
                auto n = fruits[left++];
                --cnt[n];
                if (cnt[n] == 0) {
                    cnt.erase(n);
                }
            }
            max_len = max(max_len, i - left + 1);
       }
       return max_len;
    }
};
