class MyCircularQueue {
    int capacity = 0;
    vector<int> data;
    int left{0};
    int right{0};
public:
    MyCircularQueue(int k) : capacity(k) {
        data = vector<int>(capacity, -1);
    }
    
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        data[right] = value;
        if (right == capacity-1) {
            right = 0;
        }
        else {
            ++right;
        }
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        data[left] = -1;
        if (left == capacity-1) {
            left = 0;
        }
        else {
            ++left;
        }
        return true;
    }
    
    int Front() {
        return data[left];
    }
    
    int Rear() {
        return right == 0 ? data[capacity-1] : data[right-1];
    }
    
    bool isEmpty() {
        return left == right && data[left] == -1;
    }
    
    bool isFull() {
        return data[right] != -1;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */