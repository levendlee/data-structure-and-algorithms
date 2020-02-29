// 1102 Path With Maximum Minimum Value
// https://leetcode.com/problems/path-with-maximum-minimum-value

// version: 1; create time: 2019-12-30 11:34:15;
    int maximumMinimumPath(vector<vector<int>>& A) {
        int m = A.size();
        if (m == 0) return 0;
        int n = A[0].size();
        if (n == 0) return 0;

        vector<vector<int>> min_values(m, vector<int>(n, INT_MIN));
        priority_queue<pair<int, int>> pq;
        pq.emplace(A[0][0], 0);

        constexpr int offsets[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        constexpr int mask = ((1 << 15) - 1);

        while (!pq.empty()) {
            const auto p = pq.top(); pq.pop();
            const int path_min = p.first;
            const int i = p.second & mask;
            const int j = (p.second >> 15) & mask;
            for (int k = 0; k < 4; ++k) {
                const int ii = i + offsets[k][0];
                const int jj = j + offsets[k][1];
                if (ii >= 0 && ii < m && jj >= 0 && jj < n) {
                    const int cur_path_min = std::min(A[ii][jj], path_min);
                    if (ii == m - 1 && jj == n - 1) {
                        return cur_path_min;
                    }
                    if (min_values[ii][jj] < cur_path_min) {
                        min_values[ii][jj] = cur_path_min;
                        pq.emplace(cur_path_min, (ii | (jj << 15)));
                    }
                }
            }
        }

        return 0;
    }
