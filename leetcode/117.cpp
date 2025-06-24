/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    vector<Node*> _rightMost;
    Node* connect(Node* root) {
        dfs(root, 0);
        std::cout << "ret\n";
        return root;
    }
    void dfs(Node* root, int step) {
        if (!root) {
            return;
        }
        std::cout << root->val << std::endl;
        if (step >= _rightMost.size()) {
            _rightMost.resize(step+ 1, nullptr);
        }
        if (_rightMost[step]) {
            _rightMost[step]->next = root;
        }
        _rightMost[step] = root;
        dfs(root->left, step+1);
        dfs(root->right, step+1);
    }
};
