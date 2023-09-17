class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        const int n = points.size();
        auto calc = [](const vector<int>& p0, const vector<int>& p1) {
            return std::abs(p0[0] - p1[0]) + std::abs(p0[1] - p1[1]);
        };
        std::priority_queue<std::array<int, 3>> cost;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                cost.push({-calc(points[i], points[j]), i, j});
            }
        }
        int total_cost = 0;
        vector<int> union_find(n);
        std::iota(union_find.begin(), union_find.end(), 0);
        for (int i = 0; i < n - 1; ++i) {
            while (union_find[cost.top()[1]] == union_find[cost.top()[2]]) {
                cost.pop();
            }
            total_cost += cost.top()[0];
            int src = union_find[cost.top()[1]];
            int dst = union_find[cost.top()[2]];
            for (auto& uf : union_find) {
                if (uf == src) {
                    uf = dst;
                }
            }
        }
        return -total_cost;
    }
};
