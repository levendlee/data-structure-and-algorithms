class Solution {
public:
    int maxIntersectionCount(vector<int>& y) {
        map<int, int> intervals;
        int n = y.size();
        for (int i = 0; i < n - 1; ++i) {
            int s = 2 * y[i];
            int e = 2 * y[i + 1] + ((i + 1 == n - 1) ? 0 : y[i + 1] > y[i] ? -1 : 1);
            int lo = min(s, e);
            int hi = max(s, e);
            ++intervals[lo];
            --intervals[hi + 1];
        }
        int max_active_intervals = 0;
        int active_intervals = 0;
        for (const auto [y, cnt] : intervals) {
            active_intervals += cnt;
            max_active_intervals = max(max_active_intervals, active_intervals);
        }
        return max_active_intervals;
    }
};