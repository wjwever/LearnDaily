/*************************************************************************
    > File Name: leetcode/133.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年06月20日 星期五 12时02分57秒
 ************************************************************************/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map<Node*, Node*> _dict;
    Node* cloneGraph(Node* node) {
        return dfs(node);
    }
    Node* dfs(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        Node* newNode = new Node(node->val);
        _dict[node] = newNode;
        for (auto sub: node->neighbors) {
            if (_dict.count(sub)) {
                newNode->neighbors.push_back(_dict[sub]);
            } else {
                newNode->neighbors.push_back(dfs(sub));
            }
        }
        return newNode;
    }
};
