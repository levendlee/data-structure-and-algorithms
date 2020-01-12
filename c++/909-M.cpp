class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        const int m = board.size();
        if (m == 0) return -1;
        const int n = board.size();
        if (n == 0) return -1;

        const auto calc_index = [&](const int k) {
            const int i = m - 1 - (k / n);
            const int j = ((k / n) % 2) ? (n - 1 - (k % n)) : (k % n);
            return std::make_pair(i, j);
        };

        vector<bool> visit(m * n, false);
        queue<int> bfs;
        bfs.push(0);
        int steps = 0;

        while (!bfs.empty()) {
            const int size = bfs.size();
            ++steps;
            for (int i = 0; i < size; ++i) {
                const auto k = bfs.front(); bfs.pop();
                for (int s = 1; (s <= 6) && (s + k < m * n); ++s) {
                    const auto index = calc_index(k + s);
                    const int i = index.first;
                    const int j = index.second;
                    const int next = board[i][j] != -1 ? board[i][j] - 1 : k + s;
                    if (next == m * n - 1) return steps;
                    if (visit[next]) continue;
                    visit[next] = true;
                    bfs.push(next);
                }
            }
        }

        return -1;
    }
};