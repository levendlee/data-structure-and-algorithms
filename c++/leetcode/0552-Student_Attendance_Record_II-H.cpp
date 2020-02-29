// 552 Student Attendance Record II
// https://leetcode.com/problems/student-attendance-record-ii

// version: 1; create time: 2019-10-22 21:09:58;
class Solution {
public:
    int checkRecord(int n) {
        const int64_t mode = pow(10, 9) + 7;

        std::array<int64_t, 6> dp, ndp;
        std::fill(dp.begin(), dp.end(), 0LL);
        dp[0] = 1;

        for (int i = 0; i < n; ++i) {
            // does not contain 'A', ends with 'P'
            ndp[0] = (dp[0] + dp[1] + dp[2]) % mode;
            // does not contain 'A', ends with one 'L'
            ndp[1] = dp[0];
            // does not contain 'A', ends with two 'L'
            ndp[2] = dp[1];
            // contains 'A', ends with 'A' or 'P'
            ndp[3] = (dp[0] + dp[1] + dp[2] + dp[3] + dp[4] + dp[5]) % mode;
            // contains 'A', ends with one 'L'
            ndp[4] = dp[3];
            // contains 'A', ends with two 'L'
            ndp[5] = dp[4];

            dp = ndp;
        }

        return std::accumulate(dp.begin(), dp.end(), 0LL) % mode;
    }
};
