class Solution {
public:
    int trapRainWater(vector<vector<int>>& hmap) {
        const int m = hmap.size();
        if (m == 0) return 0;
        const int n = hmap[0].size();
        if (n == 0) return 0;

        int water = 0;
        priority_queue<vector<int>> pq;
        for (int i = 0; i < m; ++i) {
            pq.push({-hmap[i][0], i, 0});
            if (n - 1 != 0) pq.push({-hmap[i][n-1], i, n-1});
        }
        for (int j = 1; j < n - 1; ++j) {
            pq.push({-hmap[0][j], 0, j});
            if (m - 1 != 0) pq.push({-hmap[m-1][j], m-1, j});
        }

        int cur_h = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        while (!pq.empty()) {
            auto h = -pq.top()[0], i = pq.top()[1], j = pq.top()[2]; pq.pop();
            if (i != 0 && i != m - 1 && j != 0 && j != n - 1) {
                water += max(cur_h - h, 0);
            }
            cur_h = max(cur_h, h);
            visited[i][j] = true;
            constexpr int offsets[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
            for (int k = 0; k < 4; ++k) {
                int ii = i + offsets[k][0];
                int jj = j + offsets[k][1];
                if (ii < 0 || ii >= m || jj < 0 || jj >= n || visited[ii][jj]) continue;
                visited[ii][jj] = true;
                pq.push({-hmap[ii][jj], ii, jj});
            }
        }

        return water;
    }
};