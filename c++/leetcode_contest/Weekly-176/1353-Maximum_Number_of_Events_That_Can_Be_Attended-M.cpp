// 1353 Maximum Number of Events That Can Be Attended
// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended

// version: 1; create time: 2020-02-29 22:27:56;
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int cnt = 0;
        sort(events.begin(), events.end(), [](auto& l, auto& r) { return l[1] < r[1]; });
        unordered_set<int> days;
        for (auto event : events) {
            /*
            if (event[0] <= day + 1 && event[1] >= day + 1) {
                day = day + 1;
                ++cnt;
            } else if (event[0] >= day + 1) {
                day = event[0];
                ++cnt;
            }
            */
            for (int d = event[0]; d <= event[1]; ++d) {
                if (!days.count(d)) {
                    days.insert(d);
                    break;
                }
            }
        }
        return days.size();
    }
};
