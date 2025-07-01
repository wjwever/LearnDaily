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
    std::vector<std::pair<unsigned long long, unsigned long long>> data;
    int widthOfBinaryTree(TreeNode* root) {
        dfs(root, 0, 0);
        unsigned long long res = 0;
        for (auto& p : data) {
            std::cout << p.first << " " << p.second << std::endl;
            res = max(res, p.second - p.first + 1);
        }
        return res;
    }

    void dfs(TreeNode* node , int step, unsigned long long num) {
        if (!node) {
            return;
        }
        if (data.size() <= step + 1) {
            data.resize(step + 1);
        }
        if (data[step].first == 0) {
            data[step].first = num;
        }
        data[step].second = max(data[step].second, num);
        dfs(node->left, step + 1, num * 2 + 1);
        dfs(node->right, step + 1, num * 2 + 2);
    }
};
