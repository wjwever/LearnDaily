/*************************************************************************
    > File Name: leetcode/102.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年06月21日 星期六 08时58分25秒
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
    vector<vector<int>> res;
    vector<vector<int>> levelOrder(TreeNode* root) {
       dfs(root, 0);
       return res;
    }
    void dfs(TreeNode* node, int step) {
        if (!node) {
            return;
        }
        if (res.size() <= step) {
            res.resize(step + 1);
        }
        res[step].push_back(node->val);
        dfs(node->left, step+1);
        dfs(node->right, step+1);
    }
};

int main()
{
    return 0;
}

