class MedianFinder {
    std::priority_queue<int, vector<int>> left_;
    std::priority_queue<int, vector<int>, std::greater<int>> right_;
public:
    MedianFinder() {}
    
    void addNum(int num) {
        left_.push(num);
        if (!left_.empty() && !right_.empty() && left_.top() > right_.top()) {
            right_.push(left_.top());
            left_.pop();
        }
        if (left_.size() > right_.size() + 1) {
            right_.push(left_.top());
            left_.pop();
        }
        if (right_.size() > left_.size() + 1) {
            left_.push(right_.top());
            right_.pop();
        }
    }
    
    double findMedian() {
        auto lsize = left_.size();
        auto rsize = right_.size();
        if (lsize == rsize) {
            return (left_.top() + right_.top())/2.0;
        }
        if (lsize > rsize) {
            return left_.top();
        }
        return right_.top();
    }
};
