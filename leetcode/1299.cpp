/*************************************************************************
    > File Name: leetcode/1299.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月15日 星期二 16时32分44秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}


class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
       vector<int> res;
       vector<int> tmp;
       // 单调递增数组
       for (int i = arr.size() - 1; i >= 0; --i) {
            if (res.empty()) {
                res.push_back(-1);
            } else  if (arr[i + 1] > res.back()){
                while(res.size() and res.back() <= arr[i + 1]) res.pop_back();
                res.push_back(arr[i + 1]);
            }
            tmp.push_back(res.back());
       }

        for (auto c : tmp) {
            std::cout << c << '\t';
        }
        std::reverse(tmp.begin(), tmp.end());
        return tmp;
    }
};
