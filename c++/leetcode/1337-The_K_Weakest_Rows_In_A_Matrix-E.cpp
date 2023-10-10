class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        std::priority_queue<pair<int, int>> pq;
        for (int i = 0; i < mat.size(); ++i) {
            int sum = std::accumulate(mat[i].begin(), mat[i].end(), 0);
            pq.push({sum, i});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        std::vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};
