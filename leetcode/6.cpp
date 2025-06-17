class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        std::vector<std::string> mat(numRows);
        int row = 0;
        int flag = -1;
        for (const char c: s) {
            mat[row].push_back(c);
            if (row == 0 or row == numRows -1) {
                flag *= -1;
            }
            row += flag;
        }
        std::string ret;
        for (const auto& str : mat) {
            ret += str;
        }
        return ret;
    }
};
