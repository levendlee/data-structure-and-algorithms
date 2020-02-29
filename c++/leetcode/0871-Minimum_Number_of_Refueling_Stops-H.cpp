// 871 Minimum Number of Refueling Stops
// https://leetcode.com/problems/minimum-number-of-refueling-stops

// version: 1; create time: 2020-01-26 16:13:33;
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        // 1) 2D DP
        /*
        const int n = stations.size();
        vector<int> dp(n + 1, 0);
        dp[0] = startFuel;
        for (int i = 0; i < n; ++i) {       // Iterate through stations. It gurantees the order of visit.
            for (int j = i; j >= 0 && dp[j] >= stations[j][0]; --j) {   // Iterate through number of stops
                dp[j + 1] = std::max(dp[j + 1], dp[j] + stations[i][1]);
            }
        }
        for (int i = 0; i < n + 1; ++i) {
            if (dp[i] >= target) return i;
        }
        return -1;
        */

        // 2) Priority Queue
        const int n = stations.size();
        priority_queue<int> pq;
        int i = 0;
        int steps;
        int location = startFuel;
        for (steps = 0; location < target; ++steps) {
            while (i < n && location >= stations[i][0]) {
                pq.push(stations[i++][1]);
            }
            if (pq.empty()) return -1;
            location += pq.top(); pq.pop(); // We can always stop at pq.top() along the way. No matter it was before / after the previous planning.
        }
        return steps;
    }
};
