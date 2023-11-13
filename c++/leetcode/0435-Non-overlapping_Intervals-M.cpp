// 435 Non-overlapping Intervals
// https://leetcode.com/problems/non-overlapping-intervals

// version: 1; create time: 2020-02-11 19:12:15;
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

//

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int erase = 0;
        int pend = INT_MIN;
        for (const auto& interval : intervals) {
            int start = interval[0];
            int end = interval[1];
            if (pend > start) {
                ++erase;
                pend = min(end, pend);
            } else {
                pend = end;
            }

        }

        return erase;
    }
};
