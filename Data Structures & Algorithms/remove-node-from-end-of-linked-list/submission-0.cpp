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
        int sz = 0;
        auto curr = head;

        while(curr) {
            ++sz;
            curr = curr->next;
        }

        int i = 1;
        int j = sz - n;
        if (j == 0) {
            return head->next;
        }
        curr = head;
        while (i++ < j) {
            curr = curr->next;
        }
        if (curr->next) {
            curr->next = curr->next->next;
        }
        return head;
        
    }
};
