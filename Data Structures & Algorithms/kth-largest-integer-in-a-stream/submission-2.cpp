class KthLargest {
    std::priority_queue<int, std::vector<int>, std::greater<int>> q_;
    int k_;
public:
    KthLargest(int k, std::vector<int> nums) {
        k_ = k;
        for (const auto& n : nums) {
            q_.push(n);
            if (q_.size() > k_) {
                q_.pop();
            }
        }
    }
    
    int add(int val) {
        q_.push(val);
        if (q_.size() > k_) {
            q_.pop();
        }
        return q_.top();
    }
};