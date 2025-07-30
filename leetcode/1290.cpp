/*************************************************************************
    > File Name: leetcode/1290.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月14日 星期一 12时04分16秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}
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
    int getDecimalValue(ListNode* head) {
        int res = 0;
        auto tmp = head;
        while(tmp) {
            res = res * 2 + tmp->val;
            tmp = tmp->next;
        }
        return res;
    }
};
