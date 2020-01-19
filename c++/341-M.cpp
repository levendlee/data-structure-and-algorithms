/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
private:
    stack<pair<const vector<NestedInteger>*, int>> stk_;

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        stk_.emplace(&nestedList, 0);
    }

    int next() {
        hasNext();
        const auto& vec = *stk_.top().first;
        auto& idx = stk_.top().second;
        return vec[idx++].getInteger();
    }

    bool hasNext() {
        while (!stk_.empty()) {
            const auto& vec = *stk_.top().first;
            auto& idx = stk_.top().second;
            if (idx >= vec.size()) {
                stk_.pop();
            } else if (!vec[idx].isInteger()) {
                stk_.emplace(&vec[idx++].getList(), 0);
            } else {
                break;
            }
        }
        return !stk_.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */