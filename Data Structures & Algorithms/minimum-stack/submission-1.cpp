class MinStack {
    std::vector<int> m_stack;
    std::vector<int> m_min_stack;
public:
    MinStack() {
    }
    
    void push(int val) {
        m_stack.push_back(val);
        if (m_min_stack.empty() || val <= m_min_stack.back()) {
            m_min_stack.push_back(val);
        }
    }
    
    void pop() {
        if (m_stack.back() == m_min_stack.back()) {
            m_min_stack.pop_back();
        }
        m_stack.pop_back();
    }
    
    int top() {
        return m_stack.back();
    }
    
    int getMin() {
        return m_min_stack.back();
    }
};