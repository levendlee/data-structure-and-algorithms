// 1043 Partition Array for Maximum Sum
// https://leetcode.com/problems/partition-array-for-maximum-sum

// version: 1; create time: 2020-02-15 23:40:28;
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        const int n = A.size();
        vector<int> dp(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            int max_num = INT_MIN;
            for (int j = i; j >= max(i - K + 1, 0); --j) {
                max_num = max(max_num, A[j]);
                dp[i+1] = max(dp[i+1], dp[j] + (i - j + 1) * max_num);
            }
        }
        return dp[n];
    }
};
