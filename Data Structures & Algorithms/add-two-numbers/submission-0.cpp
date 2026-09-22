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
        bool carry = false;
        while(l1 && l2) {
            int s = l1->val + l2->val;
            s += carry ? 1 : 0;
            carry = s > 9 ? true : false;
            s = carry ? s % 10 : s;
            dummy->next = new ListNode(s);
            dummy = dummy->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode* rem = l1 ? l1 : l2;
        while (rem) {
            int s = rem->val;
            s += carry ? 1 : 0;
            carry = s > 9 ? true : false;
            s = carry ? s % 10 : s;
            dummy->next = new ListNode(s);
            dummy = dummy->next;
            rem = rem->next;
        }
        if (carry) {
            dummy->next = new ListNode(1);
        }
        return head->next;
    }
};
