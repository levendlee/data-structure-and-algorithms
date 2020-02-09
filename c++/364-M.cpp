/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int res = 0;

        stack<pair<vector<NestedInteger>,int>> stk;
        stk.push({nestedList, 0});

        // The folloing fashion have O(N) space complexity
        /*
        int depth = 1;
        vector<vector<int>> nums;
        while (!stk.empty()) {
            auto& nlist = stk.top().first;
            auto& idx = stk.top().second;
            if (nlist.size() <= idx) {
                stk.pop();
            } else {
                auto elem = nlist[idx++];
                if (elem.isInteger()) {
                    nums.push_back({stk.size(), elem.getInteger()});
                } else {
                    stk.push({elem.getList(), 0});
                }
            }
            depth = std::max(depth, (int)stk.size());
        }

        for (auto& v : nums) {
            res += (depth - v[0] + 1) * v[1];
        }
        */

        // Optimized for O(logN) space complexity. Assmue balanced tree.
        vector<int> sums;
        while (!stk.empty()) {
            auto& nlist = stk.top().first;
            auto& idx = stk.top().second;
            if (nlist.size() <= idx) {
                stk.pop();
            } else {
                auto elem = nlist[idx++];
                if (elem.isInteger()) {
                    if (sums.size() < stk.size()) {
                        sums.resize(stk.size());
                    }
                    sums[stk.size() - 1] += elem.getInteger();
                } else {
                    stk.push({elem.getList(), 0});
                }
            }
        }
        for (int i = 0; i < sums.size(); ++i) {
            res += sums[i] * (sums.size() - i);
        }
        return res;
    }
};