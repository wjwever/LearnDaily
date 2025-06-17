class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;    
        for (auto it = s.rbegin(); it != s.rend(); ++it) {
            if (isspace(*it)) {
                if (len == 0) {
                    continue;
                } else {
                    return len;
                }
            } else {
                ++len;
            }
        }
        return len;
    }
};
