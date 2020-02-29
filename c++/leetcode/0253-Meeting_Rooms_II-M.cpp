// 253 Meeting Rooms II
// https://leetcode.com/problems/meeting-rooms-ii

// version: 1; create time: 2019-11-04 22:45:49;
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end());
        const int n = intervals.size();
        std::priority_queue<int> endtimes;
        for (int i = 0; i < n; ++i) {
            if (!endtimes.empty() && -endtimes.top() <= intervals[i][0]) {
                endtimes.pop();
            }
            endtimes.push(-intervals[i][1]);
        }
        return endtimes.size();
    }
};
