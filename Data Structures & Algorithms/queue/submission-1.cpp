struct Node {
    int val{};
    Node* prev{nullptr};
    Node* next{nullptr};
    Node(int val) : val(val) {}
    Node(int val, Node* prev, Node* next) : val(val), prev(prev), next(next) {}
};

class Deque {
    Node* head{nullptr};
    Node* tail{nullptr};
    int size{0};
public:
    Deque() {
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void append(int value) {
        Node* newNode = new Node(value);
        if (!tail){
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void appendleft(int value) {
        Node* newNode = new Node(value);
        if (!head){
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    int pop() {
        if (isEmpty()) { return -1; }
        int val = tail->val;
        Node* toDelete = tail;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete toDelete;
        return val;
    }

    int popleft() {
        if (isEmpty()) { return -1; }
        int val = head->val;
        Node* toDelete = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete toDelete;
        return val;
    }
};