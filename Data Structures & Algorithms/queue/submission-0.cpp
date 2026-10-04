class Deque {
    std::vector<int> elems{};
public:
    Deque() {
        
    }

    bool isEmpty() {
        return elems.empty();
    }

    void append(int value) {
        elems.push_back(value);
    }

    void appendleft(int value) {
        elems.insert(elems.begin(), value);
    }

    int pop() {
        if (elems.empty()) return -1;
        int val = elems.back();
        elems.pop_back();
        return val;
    }

    int popleft() {
        if (elems.empty()) return -1;
        int val = elems.front();
        elems.erase(elems.begin());
        return val;
    }
};
