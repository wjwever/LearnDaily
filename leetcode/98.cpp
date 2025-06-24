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
    int last = 0;
    bool firstVal = false;
    bool isValidBST(TreeNode* root) {
        return check(root);
    }
    bool check(TreeNode* node) { 
        if (!node) {
            return true;
        }
        if (!check(node->left)) {
            return false;
        }
        
        if (firstVal == false) {
            last = node->val;
            firstVal = true;
        } else if (last >= node->val) {
            return false;
        } else {
            last = node->val;
        }

        return check(node->right);
    }
};
