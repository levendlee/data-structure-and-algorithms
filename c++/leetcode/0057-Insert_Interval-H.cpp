// 57 Insert Interval
// https://leetcode.com/problems/insert-interval

// version: 1; create time: 2019-11-04 22:54:52;
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        bool pushed = false;
        int merged_start = newInterval[0];
        int merged_end = newInterval[1];
        for (auto& i : intervals) {
            if (i[1] < newInterval[0]) {
                res.push_back(i);
            } else if  (i[0] > newInterval[1]) {
                if (!pushed) {
                    res.push_back({merged_start, merged_end});
                    pushed = true;
                }
                res.push_back(i);
            } else {
                merged_start = std::min(i[0], merged_start);
                merged_end = std::max(i[1], merged_end);
            }
        }
        if (!pushed) {
            res.push_back({merged_start, merged_end});
        }
        return res;
    }
};
