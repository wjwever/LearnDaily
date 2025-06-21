/*************************************************************************
    > File Name: leetcode/101.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年06月21日 星期六 08时27分26秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

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
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }
        return isSymmetric(root->left, root->right);
    }
    bool isSymmetric(TreeNode* left, TreeNode* right) {
        if (!left and !right) {
            return true;
        } else if(left and right){
            if (left->val != right->val) {
                return false;
            }
            return isSymmetric(left->right, right->left) and isSymmetric(left->left, right->right);
        } else {
            return false;
        }
    }
};

int main()
{
    return 0;
}

