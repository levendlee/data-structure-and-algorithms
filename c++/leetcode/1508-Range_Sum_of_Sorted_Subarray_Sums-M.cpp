class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<array<int, 2>> pq;
        for (int i = 0; i < n; ++i) {
            pq.push({-nums[i], i});
        }
        int sum = 0;
        const int mod = pow(10, 9) + 7;
        for (int i = 1; i <= right; ++i) {
            const auto arr = pq.top();
            pq.pop();
            if (i >= left) {
                sum += -arr[0];
                sum %= mod;
            }
            const auto end = arr[1];
            if (end < n - 1) {
                pq.push({arr[0] - nums[end + 1], end + 1});
            }
        }
        return sum;
    }
};