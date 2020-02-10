class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        const int n = startTime.size();

        vector<vector<int>> times;
        for (int i = 0; i < n; ++i) {
            times.push_back({endTime[i], startTime[i], profit[i]});
        }
        sort(times.begin(), times.end(),
            [&](const auto& l, const auto& r) { return l[0] < r[0]; });

        // Similary concept but messy code
        /*
        int running_max = 0;
        vector<int> dp(n, 0);
        for (int i = 0; i < n; ++i) {
            auto et = times[i][0];
            auto st = times[i][1];
            auto p = times[i][2];

            vector<int> bound = {st, 0, 0};
            auto pre = lower_bound(times.begin(), times.end(), bound) - times.begin();  // should replace vector with bst
            pre = (times[pre][0] == st) ? pre : pre - 1;
            if (pre >= 0) {
                dp[i] = max(running_max, dp[pre] + p);
            } else {
                dp[i] = max(running_max, p);
            }
            running_max = max(running_max, dp[i]);
        }
        return *std::max_element(dp.begin(), dp.end());
        */
        map<int, int> dp = {{0, 0}};    // At time 0, max profit is 0
        for (const auto& time : times) {
            int cur = prev(dp.upper_bound(time[1]))->second + time[2];
            if (cur > dp.rbegin()->second) {
                dp[time[0]] = cur;
            }
        }
        return dp.rbegin()->second;
    }
};