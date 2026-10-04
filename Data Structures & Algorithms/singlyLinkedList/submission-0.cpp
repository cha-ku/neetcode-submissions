struct Node {
    int val;
    Node* next;
    Node(int val) : val(val), next(nullptr) {}
    Node(int val, Node* next) : val(val),  next(next) {};
};

class LinkedList {
    Node* head{nullptr};
public:
    LinkedList() {};

    int get(int index) {
        Node* curr = head;
        while (index && curr) {
            curr = curr->next;
            index--;
        }
        return curr ? curr->val : -1;
    }

    void insertHead(int val) {
        head = new Node(val, head);
    }
    
    void insertTail(int val) {
        if (!head) {
            head = new Node(val);
            return;
        }
        Node* curr = head;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = new Node(val);

    }

    bool remove(int index) {
        Node* prev = nullptr;
        Node* curr = head;
        while (index && curr) {
            prev = curr;
            curr = curr->next;
            index--;
        }
        if (!curr) {
            return false;
        }
        if (prev) {
            prev->next = curr->next;
        } else {
            head = curr->next;
        }
        delete curr;
        return true;
    }

    vector<int> getValues() {
        Node* curr = head;
        vector<int> result;
        while (curr) {
            result.push_back(curr->val);
            curr = curr->next;
        }
        return result;
    }
};
