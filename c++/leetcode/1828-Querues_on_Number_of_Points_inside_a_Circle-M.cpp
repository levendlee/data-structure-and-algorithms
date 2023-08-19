class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        std::map<int, std::set<int>> sorted_points;
        for (const auto& xy : points) {
            sorted_points[xy[0]].insert(xy[1]);
        }
        auto square = [](const float x) { return x * x; };
        std::vector<int> num_points_in_circle;
        for (const auto& q : queries) {
            int cnt = 0;
            const int x = q[0], y = q[1], r = q[2];
            auto x0_iter = sorted_points.lower_bound(x - r);
            auto x1_iter = sorted_points.upper_bound(x + r);
            for (auto iter = x0_iter; iter != x1_iter; ++iter) {
                const int cur_x = iter->first;
                const auto& sorted_ys = iter->second;
                for (auto cur_y : sorted_ys) {
                    if (square(cur_x - x) + square(cur_y - y) <= r * r) {
                        cnt++;
                    }
                }
                /*
                const float max_y = std::floor(sqrt(r * r - (x - cur_x)*(x - cur_x)));
                auto y0_iter = sorted_ys.lower_bound(y - max_y);
                auto y1_iter = sorted_ys.upper_bound(y + max_y);
                cnt += std::distance(y0_iter, y1_iter);
                */
            }
            num_points_in_circle.push_back(cnt);
        }
        return num_points_in_circle;
    }
};
