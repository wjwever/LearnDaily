/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    std::vector<std::tuple<int, int, int >> data; // col row val
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0); 
        sort (data.begin(), data.end());
        vector<vector<int>> res;
        int lastcol = INT_MIN;
        for (auto& [col, row, value]: data) {
            if (col != lastcol) {
                lastcol = col;
                res.emplace_back();
            }
            res.back().push_back(value);
        }
        return res;
    }
    void dfs(TreeNode* node, int row, int col) {
        if (!node) {
            return;
        }
        data.push_back(std::make_tuple(col, row,  node->val));
        dfs(node->left,  row + 1,  col - 1);
        dfs(node->right, row + 1, col + 1);
    }
};
