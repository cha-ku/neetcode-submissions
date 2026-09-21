/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        std::unordered_map<Node*, Node*> copies;

        auto curr = head;
        Node* dummy = new Node(0);
        Node* res = dummy;
        while (curr) {
            dummy->next = new Node(curr->val);
            copies[curr] = dummy->next;
            curr = curr->next;
            dummy = dummy->next;
        }
        for (const auto& [orig, copied]: copies) {
            if (orig->random) {
                copied->random = copies[orig->random];
            }
        }
        return res->next;
    }
};
