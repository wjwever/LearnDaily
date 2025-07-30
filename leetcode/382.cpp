/*************************************************************************
    > File Name: leetcode/382.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月09日 星期三 16时55分12秒
 ************************************************************************/
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
    ListNode* _head = nullptr;
    Solution(ListNode* head) {
        _head  = head;
    }

    int getRandom() {
        int i = 1;
        int ans = 0;
        auto pt = _head;
        while(pt) {
            if(rand() % i == 0) {
                ans = pt->val;
            }
            pt = pt->next;
            ++i;
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
