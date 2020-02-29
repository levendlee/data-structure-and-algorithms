// 630 Course Schedule III
// https://leetcode.com/problems/course-schedule-iii

// version: 1; create time: 2020-01-22 19:53:46;
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        const int n = courses.size();
        std::sort(courses.begin(), courses.end(), [](const auto& lhs, const auto& rhs) { return lhs[1] < rhs[1]; });
        /*
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            vector<int> ndp = dp;
            for (int j = 0; j <= i; ++j) {
                if (dp[j] == INT_MAX) continue;
                if (dp[j] + courses[i][0] <= courses[i][1]) {
                    ndp[j+1] = std::min(ndp[j+1], dp[j] + courses[i][0]);
                }
            }
            dp = std::move(ndp);
        }
        for (int i = n; i >= 0; --i) {
            if (dp[i] != INT_MAX) return i;
        }
        */
        int time = 0;
        std::priority_queue<int> pq;
        for (int i = 0; i < n; ++i) {
            time += courses[i][0];
            pq.push(courses[i][0]);
            if (time > courses[i][1]) {
                time -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};
