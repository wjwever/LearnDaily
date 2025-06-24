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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1 and !list2) {
            return nullptr;
        }
        else if (!list2) {
            return list1;
        } else if (!list1) {
            return list2;
        } else {
            if (list1->val < list2->val) {
                auto next = mergeTwoLists(list1->next, list2);
                list1->next = next;
                return list1;
            } else {
                auto next = mergeTwoLists(list1, list2->next);
                list2->next = next;
                return list2;
            }
        }
    }
};
