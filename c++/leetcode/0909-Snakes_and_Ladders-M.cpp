// 909 Snakes and Ladders
// https://leetcode.com/problems/snakes-and-ladders

// version: 1; create time: 2020-01-12 11:30:15;
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

// 2023/10/21
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        const int n = board.size();

        std::queue<int> bfs;
        bfs.push(1);

        auto decode = [&](int x) {
            int i = (x - 1) / n;
            int j = x - i * n;
            j = i % 2 ? (n - j) : (j - 1);
            i = n - i - 1;
            return std::make_pair(i, j);
        };

        int steps = 0;
        while (!bfs.empty()) {
            int size = bfs.size();
            for (int k = 0; k < size; ++k) {
                auto idx = bfs.front();
                bfs.pop();
                for (int l = 1; l <= 6; ++l) {
                    int next_idx = idx + l;
                    if (next_idx > n * n) {
                        continue;
                    }
                    auto next_ij = decode(next_idx);
                    auto& ladder = board[next_ij.first][next_ij.second];
                    if (ladder == -100) {
                        continue;
                    }
                    if (ladder != -1) {
                        next_idx = ladder;
                    }
                    ladder = -100;
                    if (next_idx == n * n) {
                        return steps + 1;
                    } else {
                        bfs.push(next_idx);
                    }
                }
            }
            ++steps;
        }

        return -1;
    }
};

