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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return add(l1, l2, 0);
    }

    ListNode* add(ListNode* l1, ListNode* l2, int carry) {
        int value;
        if (l1 and l2) {
            value = (l1->val + l2->val + carry) % 10;
            carry = (l1->val + l2->val + carry) / 10;
            auto node = new ListNode(value);
            node ->next = add(l1->next, l2->next, carry);
            return node;
        } else if (l1) {
            value   =   (l1->val + carry) % 10;
            carry  =   (l1->val + carry) / 10;
            auto node = new ListNode(value);
            node ->next = add(l1->next, nullptr, carry);
            return node;
        } else if (l2) {
            value   =   (l2->val + carry) % 10;
            carry  =   (l2->val + carry) / 10;
            auto node = new ListNode(value);
            node ->next = add(l2->next, nullptr, carry);
            return node;
        } else if (carry) {
            return new ListNode(carry);
        }
        return nullptr;
    }
};
