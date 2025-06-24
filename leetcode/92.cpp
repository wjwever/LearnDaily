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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;

        ListNode* pre = dummy;
        ListNode* cur = head;
        ListNode* next = nullptr;
        int n = 1;
        ListNode* n1 = nullptr;
        while(cur) {
            next = cur->next;
            if (n < left) {
                
            } else if (n <= right) {
                cur->next = pre;
                std::cout << cur->val  << " -> " << cur->next->val << std::endl;
                if (!n1) {
                    n1 = cur;
                }
            } else {
                break;
            }
            pre = cur;
            cur = next;
            n++;
        }
        //std::cout << n1->val << "\t" << pre->val << "\t" << cur->val << std::endl;
        if (n1) {
            #if 0
            std::cout << n1->val << "\n";
            std::cout << pre->val << "\n";
            std::cout << cur->val << "\n";
            std::cout << next->val << "\n";
            #endif

            std::cout << pre->next->val << "\n";
            std::cout << n1->next->val << "\n";
            n1->next->next  = pre;
            n1->next = cur;
        }
        return dummy->next;
    }
};
