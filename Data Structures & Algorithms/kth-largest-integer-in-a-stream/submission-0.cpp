class KthLargest {
    std::vector<int> v_;
    int k_;
public:
    KthLargest(int k, std::vector<int> nums) {
        v_ = nums;
        k_ = k;
    }
    
    int add(int val) {
        v_.push_back(val);
        std::priority_queue q(v_.begin(), v_.end());
        int t = k_;
        while(--t) {
            q.pop();
        }
        return q.top();
    }
};