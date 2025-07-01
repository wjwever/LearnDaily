class Solution {
public:
    std::set<int> visited;
    int Max = 0;
    int arrayNesting(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            dfs(i, 0, nums);
        }
        return Max;
    }

    void dfs(int n, int res, vector<int>& nums) {
        //std::cout << "check:" << n << std::endl;
        if (visited.count(n)) {
            return;
        }
        visited.insert(n);
        ++res;
        Max = max(res, Max);
        dfs(nums[n], res, nums);
    }
};
