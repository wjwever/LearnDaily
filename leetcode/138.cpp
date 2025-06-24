/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
       if (!head) {
        return NULL;
       }
       std::map<Node*, Node*> dict; 
       Node* newHead = new Node(head->val);
       dict[head] = newHead;
       auto old = head;
       auto tmp = newHead;
       while(old->next) {
            tmp->next = new Node(old->next->val);
            dict[old->next] = tmp->next;
            tmp = tmp->next;
            old = old->next;
       }
       std::cout << 1 << "\n";
       tmp =  newHead;
       while(head) {
        if (head->random) {
            tmp->random = dict[head->random];
        }
        tmp = tmp->next;
        head = head->next;
       }
       return newHead;
    }
};
