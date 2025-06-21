class Solution {
public:
    bool isAnagram(string s, string t) {
       std::map<char, int> dict; 
       for (char c : s) {
        ++dict[c];
       }
       for (char c : t) {
        --dict[c];
        if (dict[c] == 0) {
            dict.erase(c);
        }
       }

       return dict.size() == 0;
    }
};
