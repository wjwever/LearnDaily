class Solution {
public:
    int romanToInt(string s) {
        std::map<char, int> values {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int total = 0;
        for (int i=0; i< s.size(); ++i) {
            int cur = values[s[i]];
            if (i < s.size() - 1 and values[s[i]] < values[s[i + 1]]) {
                cur *= -1;
            }
            total += cur;
        }
        return total;
    }
};
