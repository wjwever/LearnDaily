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
    ListNode* deleteDuplicates(ListNode* head) {
        auto dummy = new ListNode(1e7);
        dummy->next = head;

        auto cur = head;
        auto pre = dummy;
        while(cur) {
            auto next = cur -> next;
            if (next and cur -> val == next->val) {
                while(cur and cur->val == next->val) {
                    cur = cur->next;
                }
            } else {
                pre->next = cur;
                pre = cur;
                cur = cur->next;
            }
        }
        pre->next = cur;
        return dummy->next;
    }
};
