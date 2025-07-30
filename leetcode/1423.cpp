/*************************************************************************
    > File Name: leetcode/1423.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月20日 星期日 09时51分53秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int num = cardPoints.size() - k;
        int sum  = std::accumulate(cardPoints.begin(),
        cardPoints.end(), 0); 
        if (num <= 0) {
            return sum;
        }
        int cur_sum = 0;
        int cur_min_sum = INT_MAX;
        for (int i = 0; i < cardPoints.size(); ++i) {
            cur_sum += cardPoints[i];
            if (i < num-1) {
                continue;
            }
            cur_min_sum = min(cur_min_sum, cur_sum);
            std::cout << i << "\t" << cur_sum << "\t" << cur_min_sum << std::endl;
            cur_sum -= cardPoints[i - num + 1];
        }
        return sum - cur_min_sum;
    }
};
