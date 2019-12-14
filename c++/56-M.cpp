class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if (intervals.empty()) return res;

        std::sort(intervals.begin(), intervals.end());
        for (const auto& it : intervals) {
            if (res.empty() || res.back()[1] < it[0]) {
                res.push_back(it);
            } else {
                res.back()[1] = std::max(res.back()[1], it[1]);
            }
        }

        return res;
    }
};