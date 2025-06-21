class Solution {
public:
    vector<vector<char>> _board;
    bool isValidSudoku(vector<vector<char>>& board) {
        _board = board;
        for (int i =0; i< 9; ++i) {
            if (row(i) == false) {
                return false;
            }
        }
        for (int a = 0; a < 9; ++a) {
            if (col(a) == false) {
                return false;
            }
        }
        for (int x = 0; x < 9; x+=3) {
            for (int y = 0; y < 9; y+=3) {
                if (square(x,y) == false) {
                    return false;
                }
            }
        }
        return true;
    }
    bool row(int a) {
        std::set<int> tmp;
        for (auto c : _board[a]) {
            if (c == '.') {
                continue;
            }
            if (tmp.count(c)) {
                return false;
            }
            tmp.insert(c);
        }
        return true;
    }
    bool col(int column) {
        std::set<int> tmp;
        for (int i = 0; i < 9; ++i) {
            char c = _board[i][column];
            if (c == '.') {
                continue;
            }
            if (tmp.count(c)) {
                return false;
            }
            tmp.insert(c);
        }
        return true;
    }
    bool square(int x, int y) {
        set<int> tmp;
        for (int a = 0; a < 3; ++a) {
            for (int b = 0; b < 3; ++b) {
                char c = _board[x + a][y+b];
                if (c == '.') {
                    continue;
                }
                if (tmp.count(c)) {
                    return false;
                }
                tmp.insert(c);
            }
        }
        return true;
    }
};
