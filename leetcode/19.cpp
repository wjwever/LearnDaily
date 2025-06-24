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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto dummy = new ListNode(0);
        dummy->next = head;
        int len = 0;
        auto tmp = dummy;
        while(tmp) {
            ++len;
            tmp = tmp->next;
        }
        int N = len - n -1;
        std::cout << N << std::endl;
        tmp = dummy;
        while(N-- and tmp) {
            std::cout << tmp->val << std::endl;
            tmp = tmp->next;
        }
        std::cout << tmp->val << std::endl;

        if (tmp) {
            if (tmp->next) {
                tmp->next = tmp->next->next;
            } else {
                tmp->next = nullptr;
            }
        }
        return dummy->next;
    }
};
