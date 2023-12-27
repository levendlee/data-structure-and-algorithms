// 341 Flatten Nested List Iterator
// https://leetcode.com/problems/flatten-nested-list-iterator

// version: 1; create time: 2020-01-19 16:23:16;
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

//

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        nested_list_ = nestedList;
        stk_.push({nested_list_, 0});
        cleanUp();
    }
    
    int next() {
        auto& [list, index] = stk_.top();
        int ret = list[index].getInteger();
        index += 1;
        cleanUp();
        return ret;
    }
    
    bool hasNext() {
        return !stk_.empty();
    }

private:
    void cleanUp() {
        while (!stk_.empty()) {
            auto [list, index] = stk_.top();
            if (list.size() <= index) {
                stk_.pop();
                if (stk_.empty()) return;
                stk_.top().second += 1;
            } else if (!list[index].isInteger()) {
                stk_.push({list[index].getList(), 0});
            } else {
              break;
            }
        }
    }

    void iterate() {

    }

    vector<NestedInteger> nested_list_;
    stack<pair<vector<NestedInteger>&, int>> stk_;
};
