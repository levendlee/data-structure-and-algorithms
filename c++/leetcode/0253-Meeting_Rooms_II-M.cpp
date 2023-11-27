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

//

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        size_t rooms = 0;

        sort(intervals.begin(), intervals.end());
        priority_queue<int> end_times;
        for (const auto& it : intervals) {
            int i = it[0], j = it[1];
            while (!end_times.empty() && -end_times.top() <= i) {
                end_times.pop();
            }
            end_times.push(-j);
            rooms = max(end_times.size(), rooms);
        }

        return rooms;
    }
};

