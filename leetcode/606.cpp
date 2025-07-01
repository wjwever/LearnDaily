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
    std::string res;
    string tree2str(TreeNode* root) {
        dfs(root); 
        return res;
    }
    void dfs(TreeNode* node) {
        if (!node) {
            return;
        }
        res += std::to_string(node->val);

        if (node->right) {
            res += "(";
            dfs(node->left);
            res += ")";
            res += "(";
            dfs(node->right);
            res += ")";
        } else if (node->left) {
            res += "(";
            dfs(node->left);
            res += ")";
        }
    }
};
