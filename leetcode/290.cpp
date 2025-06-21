class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> split_s;
        istringstream str(s);
        string out;
        while(str >> out){
            split_s.push_back(out);
        }

        if (split_s.size() != pattern.size()) {
            return false;
        }

        map<string, char> dict1;
        map<char, string> dict2;
        for (int i = 0; i < split_s.size(); ++i) {
            if (dict1.count(split_s[i]) and dict1[split_s[i]] != pattern[i]) {
                return false;
            }
            if (dict2.count(pattern[i]) and dict2[pattern[i]] != split_s[i]) {
                return false;
            }
            dict1[split_s[i]] = pattern[i];
            dict2[pattern[i]] = split_s[i];
        }
        return true;
    }
};


#if 0
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
#endif
