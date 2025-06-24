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
    int res = INT_MIN;
    int index = 0;
    int kthSmallest(TreeNode* root, int k) {
        search(root, k); 
        return res;
    }

    void search(TreeNode* node, int k) {
        if (!node) {
            return;
        }
        if (index < k) {
            search(node->left, k);
        }
        ++index;
        if (index == k) {
            res = node->val;
        }
        if (index < k) {
            search(node->right, k);
        }
    }
};
