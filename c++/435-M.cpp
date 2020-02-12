class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](auto& l, auto& r) { return l[1] < r[1]; });
        int endtime = INT_MIN;
        int cnt = 0;
        for (const auto& it : intervals) {
            if (endtime <= it[0]) {
                endtime = it[1];
                ++cnt;
            }
        }
        return intervals.size() - cnt;
    }
};