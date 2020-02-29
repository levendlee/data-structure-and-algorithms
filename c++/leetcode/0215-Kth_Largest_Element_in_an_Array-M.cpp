// 215 Kth Largest Element in an Array
// https://leetcode.com/problems/kth-largest-element-in-an-array

// version: 1; create time: 2020-01-30 21:32:08;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (const auto& n : nums) {
            pq.push(-n);
            if (pq.size() > k) pq.pop();
        }
        return -pq.top();
    }
};
