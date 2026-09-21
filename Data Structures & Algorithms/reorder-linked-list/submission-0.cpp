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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* newHead = slow->next;
        ListNode* prev = nullptr;
        slow->next = nullptr;
        while (newHead) {
            ListNode* tmp = newHead->next;
            newHead->next = prev;
            prev = newHead;
            newHead = tmp;
        }
        newHead = prev;
        while (newHead) {
            ListNode* tmp1 = head->next;
            ListNode* tmp2 = newHead->next;
            head->next = newHead;
            newHead->next = tmp1;
            head = tmp1;
            newHead = tmp2;
        }
    }
};