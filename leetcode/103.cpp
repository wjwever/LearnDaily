/*************************************************************************
    > File Name: leetcode/103.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年06月21日 星期六 11时28分49秒
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) {
            return res;
        }
        std::vector<TreeNode* > vec(1, root);
        std::vector<TreeNode* > newVec;
        int step = 0;
        while(vec.size() > 0) {
            if (step % 2 == 1) {
                for (int i = vec.size()-1; i>=0; --i) {
                    if (vec[i]) {
                        if (step >= res.size()) {
                            res.resize(step + 1);
                        }
                        res[step].push_back(vec[i]->val);
                    }
                }
            } else {
                for (int i = 0; i < vec.size() ; ++i) {
                    if (vec[i]) {
                        if (step >= res.size()) {
                            res.resize(step + 1);
                        }
                        res[step].push_back(vec[i]->val);
                    }
                }
            }
            for (auto n : vec) {
                if (n)  {
                    std::cout << n->val << std::endl;
                    newVec.push_back(n->left) ;
                    newVec.push_back(n->right) ;
                }
            }
            vec = newVec; newVec.clear();
            step ++;
        }
        return res;
    }
};

int main()
{
    return 0;
}

