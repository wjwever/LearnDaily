class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 对角线翻转 
        int n = matrix.size(); 
        for (int row = 0; row < n - 1; ++row) {
            for (int col = row + 1 ; col < n; ++col) {
                std::cout << row << " " << col << std::endl;
                std::swap(matrix[row][col], matrix[col][row]);
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout<< std::endl;
        }
        // Y轴翻转
        for (int row = 0 ; row < n; ++row) {
            for (int col = 0; col < n / 2; ++col) {
                //std::cout << row << " " << col << " " << n / 2  << " " << n - col  << std::endl;
                std::swap(matrix[row][col], matrix[row][n -1 - col]);
            }
        }
    }
};
