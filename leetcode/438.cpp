class Solution {
public:
    //std::string encode(const std::string& p, int start , int end) {
    //    std::map<char, int> dict; 
    //    for (int i = start; i < end and i < p.size(); ++i) {
    //        dict[p[i]]++;
    //    }
    //    std::string res;
    //    for (auto& [key, val]: dict) {
    //        res += key;
    //        res += std::to_string(val);
    //    }
    //    return res;
    //}



    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size()) {
            return std::vector<int>();
        }

        vector<int> res;
        std::vector<int> sCount(26, 0);
        std::vector<int> pCount(26, 0);
    
        for (int i = 0; i < p.size(); ++i) {
            ++sCount[s[i] - 'a'];
            ++pCount[p[i] - 'a'];
        }
        if (sCount == pCount) {
            res.push_back(0);    
        }

        for (int i = 0; i < s.size() -p.size(); ++i) {
            std::cout << i << std::endl;
            --sCount[s[i]-'a'];
            ++sCount[s[i + p.size()] - 'a'];
            if (sCount == pCount) {
                res.push_back(i + 1);
            }
        }
        return res;
    }
};
