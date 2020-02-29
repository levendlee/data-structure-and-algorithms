// 939 Minimum Area Rectangle
// https://leetcode.com/problems/minimum-area-rectangle

// version: 1; create time: 2019-10-29 23:29:14;
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        /*
        unordered_map<int, vector<int>> x_map;
        unordered_map<unsigned int, vector<int>> y_map;
        for (auto& p : points) {
            x_map[p[0]].push_back(p[1]);
        }
        for (auto& xp : x_map) {
            const auto& vec = xp.second;
            const int n = vec.size();
            for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    const int u = std::max(vec[i], vec[j]);
                    const int d = std::min(vec[i], vec[j]);
                    int loc = (u << 16) | d;
                    y_map[loc].push_back(xp.first);
                }
            }
        }
        int min_area = INT_MAX;
        for (auto& yp : y_map) {
            const int u = (yp.first >> 16);
            const int d = (yp.first & ((1 << 16) - 1));
            const int h = abs(u - d);
            auto& vec = yp.second;
            std::sort(vec.begin(), vec.end());

            if (h >= min_area) continue;

            const int n = vec.size();
            for (int i = 1; i < n; ++i) {
                min_area = std::min(min_area, h * (vec[i] - vec[i-1]));
            }
        }
        */

        unordered_map<unsigned int, int> prev_x;
        std::sort(points.begin(), points.end());

        int min_area = INT_MAX;
        const int n = points.size();
        int i = 0;
        while (i < n) {
            int j = i + 1;
            while ((j < n) && (points[j-1][0] == points[j][0])) ++j;
            const int x = points[i][0];
            for (int k = i; k < j; ++k) {
                const int y0 = points[k][1];
                for (int l = k + 1; l < j; ++l) {
                    const int y1 = points[l][1];

                    unsigned int hash = (static_cast<unsigned int>(y0) << 16) | y1;
                    if (prev_x.count(hash)) {
                        min_area = std::min(min_area, (x - prev_x[hash]) * (y1 - y0));
                    }
                    prev_x[hash] = x;
                }
            }
            i = j;
        }
        return min_area == INT_MAX ? 0 : min_area;
    }
};
