class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        stack_.push(val);
        if (decreasing_stack_.empty() || val <= decreasing_stack_.top()) {
            decreasing_stack_.push(val);
        }
    }
    
    void pop() {
        if (stack_.top() == decreasing_stack_.top()) {
            decreasing_stack_.pop();
        }
        stack_.pop();
    }
    
    int top() {
        return stack_.top();
    }
    
    int getMin() {
        return decreasing_stack_.top();
    }

private:
    std::stack<int> stack_;
    std::stack<int> decreasing_stack_;
};
