/*************************************************************************
    > File Name: leetcode/1343.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月19日 星期六 20时57分57秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        long long max_thres  = k * (long long)threshold;
        long long sum = 0;
        int cnt = 0;
        for (int i = 0; i < arr.size(); ++i) {
            sum += arr[i];
            if (i < k - 1) {
                continue;
            }
            if (sum >= max_thres) {
                ++cnt;
            }
            sum -= arr[i - k + 1];
        }
        return cnt;
    }
};
