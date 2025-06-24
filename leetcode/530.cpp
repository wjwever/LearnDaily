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
    int last=INT_MIN;
    int res = INT_MAX;
    int getMinimumDifference(TreeNode* root) {
       dfs(root); 
       return res;
    }

    void dfs(TreeNode* node) {
        if (!node) {
            return;
        }
        dfs(node->left);
        if (last == INT_MIN) {
            last = node->val;
        } else {
           res = min(res, node->val - last); 
           last = node->val;
        }
        dfs(node->right);
    }
};
