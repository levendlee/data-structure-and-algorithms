// 963 Minimum Area Rectangle II
// https://leetcode.com/problems/minimum-area-rectangle-ii

// version: 1; create time: 2020-02-04 21:18:45;
class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        set<pair<int, int>> points_set;
        for (const auto& p : points) {
            points_set.insert({p[0], p[1]});
        }

        const auto is_perpendicular = [&](const int i, const int j, const int k) {
            return (points[i][0] - points[j][0])*(points[j][0] - points[k][0]) + \
                   (points[i][1] - points[j][1])*(points[j][1] - points[k][1]) == 0;
        };

        const auto calc_dist = [&](const int i, const int j) {
            double x = points[i][0] - points[j][0];
            double y = points[i][1] - points[j][1];
            return std::sqrt(x * x + y * y);
        };

        double min_area = -1;
        const int n = points.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                auto dist1 = calc_dist(i, j);
                if (i == j || min_area > 0 && dist1 > min_area) continue;
                for (int k = 0; k < n; ++k) {
                    auto dist2 = calc_dist(j, k);
                    if (!is_perpendicular(i, j, k)) continue;
                    if (i == k || j == k || min_area > 0 && dist2 > min_area) continue;
                    int target_x = points[k][0] + points[i][0] - points[j][0];
                    int target_y = points[k][1] + points[i][1] - points[j][1];
                    auto target_hash = std::make_pair(target_x, target_y);
                    if (points_set.count(target_hash)) {
                        if (min_area < 0)
                            min_area = dist1 * dist2;
                        else
                            min_area = std::min(min_area, dist1 * dist2);
                    }
                }
            }
        }

        return min_area < 0 ? 0 : min_area;
    }
};
