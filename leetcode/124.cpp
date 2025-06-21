/*************************************************************************
    > File Name: leetcode/124.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年06月21日 星期六 09时56分51秒
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
    int curMax = INT_MIN;
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return curMax;
    }

    int dfs(TreeNode* node) {
        if (!node) {
            return 0;
        }
        int left = max(0, dfs(node->left));
        int right = max(0, dfs(node->right));
        curMax = max(curMax, left + right + node->val);
        return node->val + max(left, right);
    }
};

int main()
{
    return 0;
}

