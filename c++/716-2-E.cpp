class MaxStack {
private:
    stack<int> stk_;
    stack<int> max_stk_;

public:
    /** initialize your data structure here. */
    MaxStack() {

    }

    // All O(1). Except popMax() O(N).
    void push(int x) {
        stk_.push(x);
        auto max_v = max_stk_.empty() ? x : std::max(x, max_stk_.top());
        max_stk_.push(max_v);
    }

    int pop() {
        auto v = stk_.top(); stk_.pop();
        max_stk_.pop();
        return v;
    }

    int top() {
        return stk_.top();
    }

    int peekMax() {
        return max_stk_.top();
    }

    int popMax() {
        auto max_v = peekMax();
        stack<int> buffer;
        while (top() != max_v) {
            buffer.push(top());
            pop();
        }
        pop();
        while (!buffer.empty()) {
            push(buffer.top()); buffer.pop();
        }
        return max_v;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */