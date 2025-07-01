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
    std::vector<int> res;
    vector<int> largestValues(TreeNode* root) {
       dfs(root, 0); 
       return res;
    }

    void dfs(TreeNode* root, int depth) {
        if (!root) {
            return ;
        } 
        if(depth >= res.size()){
            res.resize(depth + 1);
            res[depth] = root->val;
        } else {
            res[depth] = max(res[depth], root->val);
        }
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }
};
