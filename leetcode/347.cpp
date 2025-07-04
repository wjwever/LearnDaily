
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map <int, int> dict;
        for (auto c : nums)
            ++dict[c];
//        int maxCnt = 0;
//        for(auto p : dict)
 //           maxCnt = max(maxCnt, p.second);
        
        map<int, vector<int> > cnt2Val; 
        for(auto p : dict)
        {
            int cnt = p.second; 
            cnt2Val[cnt].push_back(p.first);
        }
        
        vector<int> res;
        
        for(auto it = cnt2Val.rbegin(); it != cnt2Val.rend() && k > 0; ++it)
        {
            res.insert(res.end(), it -> second.begin(), it -> second.end());
            k -= it -> second.size();
        }
        return res; 
    }
};
