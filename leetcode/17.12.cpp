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
    TreeNode* _last = nullptr;
    TreeNode* _head = nullptr;
    TreeNode* convertBiNode(TreeNode* root) {
        dfs(root); 
        return _head;
    }
    void dfs(TreeNode* root) {
        if( !root ) {
            return;
        }
        dfs(root->left);
        if (!_head) {
            _head = root;
        }
        if (!_last) {
            _last = root;
        } else {
            _last->right = root;
            //_last->left = nullptr;
            _last = root;
            root->left = nullptr;
        }
        if (_last) {
            std::cout << _last->val << "->" << root->val << std::endl;
        }
        dfs(root->right);
    }
};
