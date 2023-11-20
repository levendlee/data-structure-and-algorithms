// 973 K Closest Points to Origin
// https://leetcode.com/problems/k-closest-points-to-origin

// version: 1; create time: 2019-12-30 11:34:15;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<tuple<int32_t, int16_t, int16_t>> pq;
        for (const auto& p : points) {
            const int16_t x = p[0];
            const int16_t y = p[1];
            pq.emplace(x*x + y*y, x, y);
            if (pq.size() > K) {
                pq.pop();
            }
        }
        const int n = pq.size();
        vector<vector<int>> res(n, vector<int>(2, 0));
        for (int i = 0; i < n; ++i) {
            const auto& tpl = pq.top();
            res[i][0] = std::get<1>(tpl);
            res[i][1] = std::get<2>(tpl);
            pq.pop();
        }
        return res;
    }
};

//

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<long long, int>> pq;
        const int n = points.size();
        for (int i = 0; i < n; ++i) {
            long long x = points[i][0], y = points[i][1];
            long long d2 = x * x + y * y;
            pq.push({d2, i});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<vector<int>> res;
        while (!pq.empty()) {
            auto [d2, i] = pq.top();
            pq.pop();
            res.push_back(points[i]);
        }
        return res;
    }
};
