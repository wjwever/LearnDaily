/*************************************************************************
    > File Name: leetcode/79.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年06月20日 星期五 17时59分20秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> book;
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size(), col = board[0].size();
        for (int x = 0; x < row; ++x) {
            for (int y = 0; y < col; ++y) {
                book = std::vector<vector<int>>(row, vector<int>(col, 0));
                if (dfs(x, y, 0, word, board)) {
                    std::cout << x << " " << y << std::endl;
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(int x, int y, int step, string& word, vector<vector<char>>& board) {
        if (step == word.size()) {
            return true;
        }
        if (x < 0 or y < 0 or x >= board.size() or y >= board[0].size()) {
            return false;
        }
        if (book[x][y]) {
            return false;
        }
        if (board[x][y] != word[step]) {
            return false;
        }
        book[x][y] = 1;
        bool val =
        dfs(x-1, y, step +1, word, board) ||
        dfs(x+1, y, step +1, word, board) ||
        dfs(x, y-1, step +1, word, board) ||
        dfs(x, y+1, step +1, word, board);
        book[x][y] = 0;
        return val;
    }
};

int main()
{
    return 0;
}

