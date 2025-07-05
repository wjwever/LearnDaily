class Solution {
public:
    vector<int> dp;
    std::map<char, int>  dict;
    vector<int> partitionLabels(string s) {
        for (int i = 0; i < s.size(); ++i) {
            dict[s[i]] = i;
        }
        vector<int> res;
        int begin = 0;
        while(begin < s.size()) {
            int next = jump(begin, s);
            res.push_back(next - begin + 1);
            begin = next + 1;
        }
        return res;
    }

    int jump(int begin, string& s) {
        int curMax = begin;
        while(true) {
            if (begin > curMax) {
                break;
            }
            char c = s[begin++];
            curMax = max(curMax, dict[c]);
        }
        return curMax;
    }
};
