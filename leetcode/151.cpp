class Solution {
public:
    string reverseWords(string s) {
        std::reverse(s.begin(), s.end());
        int start = 0;

        int i = 0;
        while (i < s.size()) {
            // find word begin
            while(i < s.size() and isspace(s[i])) {
                ++i;
            }
            // find word end
            int len = 0;
            while(i < s.size() and !isspace(s[i])) {
                if (start != 0 and len == 0) {
                    std::cout << "start:" << start << std::endl;
                    s[start++] = ' ';
                }
                s[start ++] = s[i++];
                len ++;
            }
                
            if (len) {
                std::cout << len << std::endl;
                std::reverse(s.begin() + start - len, s.begin() + start);
            }
            
        }
        return s.substr(0, start);
    }
};
