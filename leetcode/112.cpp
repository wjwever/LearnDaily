/*************************************************************************
    > File Name: leetcode/112.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年06月21日 星期六 08时45分33秒
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return false;
        }
        return dfs(0, 0, root, targetSum);
    }
    bool dfs(int curSum, int step, TreeNode* node, int targetSum) {
        if (!node) {
            return false;
        }
        curSum += node->val;
        std::cout << curSum << " " << node->val << std::endl;
        if (curSum == targetSum and !node->left and !node->right) {
            return true;
        }
        bool ret = false;
        if (dfs(curSum, step + 1, node->left, targetSum)) {
            ret = true;
        }
        else if (dfs(curSum, step + 1, node->right, targetSum)) {
            ret = true;
        }
        curSum-=node->val;
        return ret;
    }
};

int main()
{
    return 0;
}

