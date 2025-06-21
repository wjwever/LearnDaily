/*************************************************************************
    > File Name: leetcode/100.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年06月20日 星期五 21时53分48秒
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p and !q)  {
            return true;
        } else if (p and q) {
            if (p->val != q->val) {
                return false;
            }
            return isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
        } else {
            return false;
        }
    }
};

int main()
{
    return 0;
}

