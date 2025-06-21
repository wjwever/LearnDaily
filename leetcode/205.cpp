class Solution {
public:
    bool isIsomorphic(string s, string t) {
       if (s.size() != t.size())  {
            return false;
       }
       std::map<char, char> dict;
       std::map<char, char> dict2;
       for (int i = 0; i < s.size(); ++i) {
           if(dict.count(s[i]) and dict[s[i]] != t[i]) {
              return false;
           }
           if (dict2.count(t[i]) and dict2[t[i]] != s[i]) {
              return false;
           }
           dict[s[i]] = t[i];
           dict2[t[i]] = s[i];
       }
       return true;
    }
};
