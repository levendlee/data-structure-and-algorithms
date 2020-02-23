class MaxStack {
private:
    stack<int> stk_;
    stack<int> max_stk_;

public:
    /** initialize your data structure here. */
    MaxStack() {

    }

    void push(int x) {
        auto max_num = max_stk_.empty() ? x : max(max_stk_.top(), x);
        max_stk_.push(max_num);
        stk_.push(x);
    }

    int pop() {
        auto ret = stk_.top();
        max_stk_.pop();
        stk_.pop();
        return ret;
    }

    int top() {
        return stk_.top();
    }

    int peekMax() {
        return max_stk_.top();
    }

    int popMax() {
        auto ret = peekMax();
        stack<int> tmp;
        while (!stk_.empty() && ret != top()) {
            tmp.push(pop());
        }
        pop();
        while (!tmp.empty()) {
            push(tmp.top()); tmp.pop();
        }
        return ret;
    }
};