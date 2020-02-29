// 496 Next Greater Element I
// https://leetcode.com/problems/next-greater-element-i

// version: 1; create time: 2020-01-19 16:02:26;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        const int n = nums2.size();
        unordered_map<int, int> next_greater;
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && nums2[stk.top()] < nums2[i]) {
                const auto j = stk.top();
                next_greater[nums2[j]] = nums2[i];
                stk.pop();
            }
            stk.push(i);
        }
        vector<int> res;
        for (const auto& number : nums1) {
            if (!next_greater.count(number)) {
                res.push_back(-1);
            } else {
                res.push_back(next_greater[number]);
            }
        }
        return res;
    }
};
