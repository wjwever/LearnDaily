class Solution {
public:
    vector<vector<int>> book;
    int islandPerimeter(vector<vector<int>>& grid) {
       int row = grid.size();
       int col = grid[0].size();
       book.resize(row, vector<int>(col, 0));
       for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (grid[i][j]) {
                dfs(grid, i, j);
            }
        }
       }

       int total = 0;
       for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (book[i][j]) {
                std::cout << i << " " << j << "\n";
                if (!valid(i, j -1, grid)) {
                    ++total;
                }
                if (!valid(i, j +1, grid)) {
                    ++total;
                }
                if (!valid(i - 1, j , grid)) {
                    ++total;
                }
                if (!valid(i + 1, j , grid)) {
                    ++total;
                }
            }
        }
       }
       return total;
    }

    bool valid(int i, int j, vector<vector<int>>& grid) {
       int row = grid.size();
       int col = grid[0].size();
       return i >= 0 and i < row and j >= 0 and j < col and book[i][j];
    }

    void dfs(vector<vector<int>>& grid, int i, int j) {
       int row = grid.size();
       int col = grid[0].size();
       if (i < 0 || j < 0 || i >= row || j >= col || book[i][j] || grid[i][j] == 0) {
            return;
       }
       book[i][j] = 1;
       dfs(grid, i, j - 1);
       dfs(grid, i, j + 1);
       dfs(grid, i-1, j);
       dfs(grid, i+1, j);
    }
};
