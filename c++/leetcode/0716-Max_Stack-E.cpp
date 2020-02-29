// 716 Max Stack
// https://leetcode.com/problems/max-stack

// version: 2; create time: 2020-02-08 21:01:13;
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


// version: 1; create time: 2020-02-08 20:55:03;
class MaxStack {
private:
    list<int> list_;
    map<int, list<list<int>::iterator>> bst_;

public:
    /** initialize your data structure here. */
    MaxStack() {

    }

    // O(logN)
    void push(int x) {
        auto iter = list_.insert(list_.end(), x);
        bst_[x].push_back(iter);
    }

    // O(logN)
    int pop() {
        auto iter = --list_.end();
        auto val = *iter;
        list_.pop_back();
        bst_[val].pop_back();
        if (bst_[val].empty()) {
            bst_.erase(val);
        }
        return val;
    }

    // O(1)
    int top() {
        return list_.back();
    }

    // O(logN) // Can be optimized to O(1)
    int peekMax() {
        return (--bst_.end())->first;
    }

    // O(logN)
    int popMax() {
        auto val = peekMax();
        auto& vec = (--bst_.end())->second;
        auto iter = vec.back();
        list_.erase(iter);
        vec.pop_back();
        if (vec.empty()) {
            bst_.erase(val);
        }
        return val;
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
