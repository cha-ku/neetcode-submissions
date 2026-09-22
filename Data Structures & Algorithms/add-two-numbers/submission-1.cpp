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
        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;
        int carry = 0;
        while (l1 || l2 || carry) {
            int l1val = l1 ? l1->val : 0;
            int l2val = l2 ? l2->val : 0;
            int s = l1val + l2val + carry;
            carry = s / 10;
            int digit = s % 10;
            dummy->next = new ListNode(digit);
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
            dummy = dummy->next;
        }
        return head->next;
    }
};
