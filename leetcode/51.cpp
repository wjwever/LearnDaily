class Solution {
public:
    std::map<int, int> col;
    std::map<int, int> dig_col, dig_add, dig_sub;
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {
        dfs(0, n);
        return res;
    }

    void dfs(int r, int n) {
        if (r >= n) {
            //if (col.size() == n) {
                std::string line(n, '.');
                vector<string> tmp (n, line);
                for (auto [r, c] : col) {
                    //std::cout << "col" << r  << " " << c << std::endl;
                    tmp[r][c] = 'Q';
                    //std::cout << tmp[i] << std::endl;
                    
                }
                res.emplace_back(tmp);
            //}
            return;
        }

        for (int c = 0; c < n; ++c) {
            if (dig_col[c] == 0 and dig_add[r + c] == 0 and dig_sub[r - c] == 0) {
                //std::cout << r << " " << c << std::endl;
                col[r] = c;
                dig_col[c] = 1;
                dig_add[r+c] = 1;
                dig_sub[r-c] = 1;
                dfs(r + 1, n);
                col.erase(r);
                dig_col[c] = 0;
                dig_add[r+c] = 0;
                dig_sub[r-c] = 0;
            }
        }
    }
};
