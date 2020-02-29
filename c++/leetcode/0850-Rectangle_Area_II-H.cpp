// 850 Rectangle Area II
// https://leetcode.com/problems/rectangle-area-ii

// version: 1; create time: 2020-01-25 15:31:51;
class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        constexpr long base = 1e9 + 7;
        set<int> y_set;
        for (const auto& rec : rectangles) {
            y_set.insert(rec[1]);
            y_set.insert(rec[3]);
        }
        vector<int> y_axis(y_set.begin(), y_set.end());

        unordered_map<int, int> yi;
        int i = 0;
        for (const auto& a : y_axis) {
            yi[a] = i++;
        }

        const int n = y_axis.size();
        vector<vector<int>> events;
        for (const auto& rec : rectangles) {
            events.push_back({rec[0],  1, yi[rec[1]], yi[rec[3]]});
            events.push_back({rec[2], -1, yi[rec[1]], yi[rec[3]]});
        }
        std::sort(events.begin(), events.end());

        vector<int> y_vec(n, 0);
        long area = 0;
        long sum_y = 0;
        long pre_x = 0;
        for (const auto& event : events) {
            area += sum_y * (event[0] - pre_x);
            area %= base;
            auto action = event[1];
            for (int i = event[2]; i < event[3]; ++i) {
                y_vec[i] += action;
            }
            sum_y = 0;
            for (int i = 0; i < n - 1; ++i) {
                if (y_vec[i] > 0) {
                    sum_y += y_axis[i+1] - y_axis[i];
                }
            }
            pre_x = event[0];
        }

        return area;
    }
};
