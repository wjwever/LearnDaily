/*************************************************************************
    > File Name: leetcode/129.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年06月21日 星期六 09时46分09秒
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
    int res = 0;
    int sumNumbers(TreeNode* root) {
        dfs(0, root);
       return res ;
    }
    void dfs(int cur, TreeNode* node) {
        if (!node) {
            return;
        }
        cur = cur* 10 + node->val;
        if (!node->left and !node->right) {
            res += cur;
            return;
        }
        dfs(cur, node->left);
        dfs(cur, node->right);
    }
};

int main()
{
    return 0;
}

