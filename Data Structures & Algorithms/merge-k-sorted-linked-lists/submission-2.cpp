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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i] != nullptr)
                pq.push(lists[i]);
        }
        ListNode* dummy = new ListNode();
        auto head = dummy;
        while (!pq.empty()) {
            ListNode* min_node = pq.top();
            pq.pop();
            dummy->next = min_node;
            if (min_node->next != nullptr)
                pq.push(min_node->next);
            dummy = dummy->next;
        }
        return head->next;
    }
};