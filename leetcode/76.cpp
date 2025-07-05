class Solution {
public:
    bool contain(vector<int>& freq, vector<int>& test) {
        for (int i = 0; i < freq.size(); ++i) {
            if (test[i] < freq[i]) {
                return false;
            }
        }
        return true;
    }
    
    int getId(char c) {
        if (c >='a' and c <='z') {
            return c-'a';
        }
        return c-'A' + 26;
    }

    string minWindow(string s, string t) {
        vector<int> freq(52, 0);
        for (auto& c : t) ++freq[getId(c)];

        int left = 0 , right = 0;
        std::string curRes = "";

        int ansL = 0, ansR = 0;

        vector<int> test(52, 0);
        while(true) {
            //std::cout << left << '\t' << right << std::endl;
            if (contain(freq, test) == false) {
                if (right >= s.size()) {
                    break;
                }
                char c = s[right];
                ++test[getId(c)];
                ++right;
            } else {
                //std::string tmp = s.substr(left, right-left);
                //std::cout << tmp << std::endl;
                if (ansR == 0 or right - left < ansR - ansL) {
                    ansR = right;
                    ansL = left;
                }
                char c = s[left];
                --test[getId(c)];
                ++left;
            }
        }
        return s.substr(ansL, ansR - ansL);
    }
};
