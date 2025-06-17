class Solution {
public:
    int hIndex(vector<int>& citations) {
        std::sort(citations.begin(), citations.end());
        int res = 0;
        for (int i = citations.size() - 1; i >= 0; --i) {
            int paper_num = citations.size() - i;
            int citation = citations[i];
            int d = min(citation, paper_num);
            res = max(res, d);
        }
        return res;
    }
};
