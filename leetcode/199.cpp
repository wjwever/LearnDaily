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
    vector<int> res;
    vector<int> rightSideView(TreeNode* root) {
        dfs(0, root);
        return res;
    }
    void dfs(int step, TreeNode* node) {
        if (!node) {
           return; 
        }
        if (step >= res.size()) {
            res.resize(step + 1, INT_MIN);
        }
        if (res[step] == INT_MIN) {
            res[step] = node->val;
        }
        dfs(step + 1, node->right);
        dfs(step + 1, node->left);
    }
};
