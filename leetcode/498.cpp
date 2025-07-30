/*************************************************************************
    > File Name: leetcode/498.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月10日 星期四 12时07分10秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> res;
        int row = mat.size();
        int col = mat[0].size();
        for (int i = 0; i < row + col -1; ++i) {
            vector<int> line;
            int x = 0, y = 0;
            if (i < row) {
                x = i, y = 0;
            } else {
                x = row - 1, y = i - x;
            }

            while(x >= 0 and y < col) {
                //std::cout << x << " " << y << std::endl;
                line.push_back(mat[x][y]);
                x -= 1;
                y += 1;
            }
            if (i % 2 == 1) {
                std::reverse(line.begin(), line.end());
            }
            res.insert(res.end(), line.begin(), line.end());
        }
        return res;
    }
};
