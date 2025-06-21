class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        std::map<char, int>  dict;
        for(auto c : magazine) ++dict[c];  
        for (auto c : ransomNote) {
            --dict[c];
            if (dict[c] < 0) {
                return false;
            }
        }
        return true;
    }
};
