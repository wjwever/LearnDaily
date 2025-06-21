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
    void flatten(TreeNode* root) {
        if (!root) {
            return ;
        }
        flatten(root->left);
        flatten(root->right);
        auto tmp = root->left;
        if (tmp) {
            while(tmp->right) {
                tmp= tmp->right;
            }
            auto bak = root->right;
            root->right = root->left;
            tmp->right = bak;
            root->left = nullptr;
        }
    }
};


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
    void flatten(TreeNode* root) {
        run(root);
    }

    TreeNode* run(TreeNode* root) {
        if(root == nullptr) {
            return root;
        }

        TreeNode* tmp1 = run(root->left);
        TreeNode* tmp2 = run(root->right);
        root->left = nullptr;
        root->right = tmp1;
        while(tmp1 and tmp1->right) {
            tmp1 = tmp1->right;
        }
        if (tmp1) {
            tmp1->right = tmp2;
        } else {
            root->right = tmp2;
        }
        return root;
    }
};


class Solution {
public:
    TreeNode* preNode;
    void flatten(TreeNode* root) {
        if (root == NULL) return;
        flatten(root->right);
        flatten(root->left);
        root->left = NULL;
        root->right = preNode;
        preNode = root;
    }
};
