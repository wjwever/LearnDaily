class Solution {
public:
    vector<int> res;
    vector<int> lexicalOrder(int n) {
       for (int t = 1; t < 10; ++t) {
            dfs(t, n); 
       }
       return res;
    }
    void dfs(int k, int n) {
        if (k > n) {
            return;
        }
        res.push_back(k);
        for (int t = 0; t < 10; t++) {
            dfs(k * 10 + t, n);
        }
    }
};
