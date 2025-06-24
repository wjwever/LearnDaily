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
    ListNode* reverseKGroup(ListNode* head, int k) {
       // reverse k eleemnts 
       int i = 0;
       int len = 0;
       ListNode* tmp = head;
       while(tmp) {
        ++len; tmp = tmp ->next;
       }
       if (len < k) {
        return head;
       }
       ListNode* pre = nullptr;
       ListNode* cur = head;
       ListNode* next = nullptr;
       for (int i= 0; i < k; ++i) {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
       }
       head->next =  reverseKGroup(cur, k);
       return pre;
    }
};
