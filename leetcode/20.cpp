class Solution {
public:
    bool isValid(string s) {
        map<char, char>  dict{{')', '('}, {']', '['}, {'}', '{'}};
        std::string res;
        for (char c : s) {
            if (dict.count(c) and res.size() and dict[c] == res.back()) {
                res.pop_back();
            }
            else {
                res.push_back(c);
            }
        }
        return res.size() == 0;
    }
};
