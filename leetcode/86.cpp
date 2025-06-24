/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) {
            return head;
        }
        auto subHead = partition(head->next, x);
        if (head->val < x) {
            head->next = subHead;
            return head;
        } else {
            head->next = subHead;
            auto tmp = head;
            while(tmp->next) {
                if (tmp->next and tmp->next->val >= x) {
                    break;
                }
                tmp = tmp->next;
            }
            if (tmp == head) {
               return head; 
            } else if (tmp) {
                head->next = tmp->next;
                tmp->next = head;
                return subHead;
            } else {
                head->next = nullptr;
                tmp->next = head;
                return subHead;
            }
        }
    }
};
