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