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
    ListNode* rotateRight(ListNode* head, int k) {
        int N = 1;
        ListNode* tail = nullptr;
        for (tail = head; tail and tail->next; tail=tail->next) {
            ++N;
        }
        k %= N;
        if (k != 0) {
            auto node = head;
            ListNode* newHead = nullptr;
            for (int i = 0; i < N; ++i) {
                if (i == N-k-1) {
                    newHead = node;
                }
                node = node->next;
            }
            tail->next = head;
            auto bk = newHead->next;
            newHead->next = nullptr;
            return bk;
        } else {
            return head;
        }
    }
};
