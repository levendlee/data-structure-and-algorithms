// 1172 Dinner Plate Stacks
// https://leetcode.com/problems/dinner-plate-stacks

// version: 1; create time: 2020-01-19 15:49:06;
class DinnerPlates {
private:
    int elements_;
    int capacity_;
    set<int> availables_;
    vector<stack<int>> stacks_;

public:
    DinnerPlates(int capacity) : capacity_(capacity) {

    }

    void push(int val) {
        ++elements_;
        if (availables_.empty()) {
            stacks_.push_back({});
            stacks_.back().push(val);
            if (capacity_ > 1) {
                availables_.insert(stacks_.size() - 1);
            }
        } else {
            auto idx = *availables_.begin();
            stacks_[idx].push(val);
            if (stacks_[idx].size() >= capacity_) {
                availables_.erase(idx);
            }
        }
    }

    int pop() {
        return popAtStack(stacks_.size() - 1);
    }

    int popAtStack(int index) {
        if (index < 0 || stacks_.size() <= index || stacks_[index].empty()) return -1;
        auto elem = stacks_[index].top(); stacks_[index].pop();
        while (!stacks_.empty() && stacks_.back().empty()) {
            availables_.erase(stacks_.size() - 1);
            stacks_.pop_back();
        }
        if (stacks_.size() > index && stacks_[index].size() < capacity_) {
            availables_.insert(index);
        }
        return elem;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
