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