class Solution {
public:
  void setZeroes(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int flag_col0 = false;
    for (int i = 0; i < m; i++) {
      if (!matrix[i][0]) {
        flag_col0 = true;
      }
      for (int j = 1; j < n; j++) {
        if (!matrix[i][j]) {
          matrix[i][0] = matrix[0][j] = 0;
        }
      }
    }
    for (int i = m - 1; i >= 0; i--) {
      for (int j = 1; j < n; j++) {
        if (!matrix[i][0] || !matrix[0][j]) {
          matrix[i][j] = 0;
        }
      }
      if (flag_col0) {
        matrix[i][0] = 0;
      }
    }
  }
};

class Solution {
public:
  void setZeroes(vector<vector<int>> &matrix) {
    int row = matrix.size(), col = matrix[0].size();
    bool flagRow0 = false, flagCol0 = false;
    for (int a = 0; a < row; ++a) {
      for (int b = 0; b < col; ++b) {
        if (matrix[a][b] == 0) {
          matrix[a][0] = 0;
          matrix[0][b] = 0;
          if (a == 0) {
            flagRow0 = true;
          }
          if (b == 0) {
            flagCol0 = true;
          }
        }
      }
    }
    for (int a = 0; a < row; ++a) {
      for (int b = 0; b < col; ++b) {
        std::cout << matrix[a][b] << " ";
      }
      std::cout << "\n";
    }
    for (int a = 1; a < row; ++a) {
      for (int b = 1; b < col; ++b) {
        if (matrix[a][0] == 0 || matrix[0][b] == 0) {
          printf("[%d][0]=%d, [0][%d]=%d\n", a, matrix[a][0], b, matrix[0][b]);
          matrix[a][b] = 0;
        }
      }
    }
#if 1
    std::cout << flagRow0 << " " << flagCol0 << std::endl;
    if (flagRow0) {
      for (auto &a : matrix[0]) {
        a = 0;
      }
    }
    if (flagCol0) {
      for (int a = 0; a < row; ++a) {
        matrix[a][0] = 0;
      }
    }
#endif
  }
};
