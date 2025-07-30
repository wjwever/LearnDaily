/*************************************************************************
    > File Name: leetcode/2134.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月21日 星期一 15时25分23秒
 ************************************************************************/

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  int minSwaps(vector<int> &nums) {
    int num1 = std::accumulate(nums.begin(), nums.end(), 0);

    nums.insert(nums.end(), nums.begin(), nums.end() - 1);
    std::cout << nums.size() << "\n";

    int max_res = 0;
    int cur_res = 0;
    for (int i = 0; i < nums.size(); ++i) {
      cur_res += nums[i];
      std::cout << "add:" << nums[i] << "\n";
      if (i < num1 - 1) {
        continue;
      }
      max_res = max(max_res, cur_res);
      std::cout << "del:" << nums[i - num1 + 1] << "\n";
      cur_res -= nums[i - num1 + 1];
    }
    std::cout << num1 << "\t" << max_res << "\n";
    return num1 - max_res;
  }
};

int main() {
  Solution s;
  vector<int> data = {0, 1, 1, 1, 0, 0, 1, 1, 0};
  s.minSwaps(data);
  return 0;
}

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int num1 = std::accumulate(nums.begin(), nums.end(), 0);
        if (num1 == 0) {
            return 0;
        }

        nums.insert(nums.end(), nums.begin(), nums.end() - 1);

        int max_res = 0;
        int cur_res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            cur_res += nums[i];
            if (i < num1 - 1) {
                continue;
            }
            max_res = max(max_res, cur_res);
            cur_res -= nums[i - num1 + 1];
        }
        return num1 - max_res;
    }
};
