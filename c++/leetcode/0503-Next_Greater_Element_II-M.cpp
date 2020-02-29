// 503 Next Greater Element II
// https://leetcode.com/problems/next-greater-element-ii

// version: 1; create time: 2020-01-07 22:14:20;
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        const int n = nums.size();
        std::stack<int> stk;
        for (int i = n-1; i >= 0; --i) {
            while (!stk.empty() && nums[i] >= stk.top()) {
                stk.pop();
            }
            stk.push(nums[i]);
        }
        vector<int> res;
        for (int i = n-1; i >= 0; --i) {
            while (!stk.empty() && nums[i] >= stk.top()) {
                stk.pop();
            }
            if (stk.empty()) {
                res.push_back(-1);
            } else {
                res.push_back(stk.top());
            }
            stk.push(nums[i]);
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};
