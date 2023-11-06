// 149 Max Points on a Line
// https://leetcode.com/problems/max-points-on-a-line

// version: 1; create time: 2020-01-25 18:19:31;
struct Line {
    int k0;
    int k1;
    long b0;
    int x;

    bool operator==(const Line& other) const {
        return k0 == other.k0 && k1 == other.k1 && b0 == other.b0 && x == other.x;
    }
};

namespace std {
    template <>
    struct hash<Line> {
        size_t operator()(const Line& line) const {
            return line.k0 ^ line.k1 ^ line.b0 ^ line.x;
        }
    };
};

int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
};

class Solution {
private:
    Line calcLine(const vector<int>& p0, const vector<int>& p1) {
        long x0 = p0[0], y0 = p0[1], x1 = p1[0], y1 = p1[1];
        if (x0 == x1) {
            return {0, 0, 0, x0};
        }
        if (x0 < x1) {
            std::swap(x0, x1);
            std::swap(y0, y1);
        }
        int k0 = x1 - x0;
        int k1 = y1 - y0;
        auto kd = gcd(abs(k0), abs(k1));
        k0 /= kd;
        k1 /= kd;
        int b0 = k1 * y1 - k0 * x1;
        return {k0, k1, b0, 0};
    }

public:
    int maxPoints(vector<vector<int>>& points) {
        const int n = points.size();
        if (n <= 1) return n;
        size_t max_points = 1;
        unordered_map<Line, unordered_set<int>> counter;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                auto line = calcLine(points[i], points[j]);
                counter[line].insert(i);
                counter[line].insert(j);
                max_points = std::max(max_points, counter[line].size());
            }
        }
        return max_points;
    }
};

//

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        const int n = points.size();
        if (n <= 2) return n;

        auto encode = [n](int i, int j) {
            if (i > j) swap(i, j);
            return i * n + j;
        };

        auto decode = [n](int k) -> pair<int, int> {
            return {k / n, k % n};
        };

        auto on_line = [&points](int a, int b, int c) {
            auto& pa = points[a], pb = points[b], pc = points[c];
            return (pa[1] - pb[1]) * (pa[0] - pc[0]) == (pa[1] - pc[1]) * (pa[0] - pb[0]);
        };

        unordered_map<int, vector<int>> edges;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    if (on_line(i, j, k)) {
                        int e0 = encode(i, j);
                        int e1 = encode(j, k);
                        int e2 = encode(i, k);

                        edges[e0].push_back(e1);
                        edges[e1].push_back(e0);
                        edges[e1].push_back(e2);
                        edges[e2].push_back(e1);
                        edges[e0].push_back(e2);
                        edges[e2].push_back(e0);
                    }
                }
            }
        }

        size_t max_points = 0;
        unordered_set<int> visited_edges;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int e = encode(i, j);
                unordered_set<int> points;
                function<void(int)> dfs;
                dfs = [&](int e) {
                    if (visited_edges.count(e)) return;
                    visited_edges.insert(e);
                    auto [i, j] = decode(e);
                    points.insert(i);
                    points.insert(j);
                    for (auto next_e : edges[e]) {
                        dfs(next_e);
                    }
                };
                dfs(e);
                max_points = max(max_points, points.size());
            }
        }

        return max_points;
    }
};

//

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        const int n = points.size();
        if (n <= 2) return n;

        auto encode = [n](int i, int j) {
            if (i > j) swap(i, j);
            return i * n + j;
        };

        auto decode = [n](int k) -> pair<int, int> {
            return {k / n, k % n};
        };

        auto on_line = [&points](int a, int b, int c) {
            auto &pa = points[a], &pb = points[b], &pc = points[c];
            return (pa[1] - pb[1]) * (pa[0] - pc[0]) == (pa[1] - pc[1]) * (pa[0] - pb[0]);
        };

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int cnt = 0;
                for (int k = j + 1; k < n; ++k) {
                    if (on_line(i, j, k)) {
                        ++cnt;
                    }
                }
                ans = max(ans, cnt + 2);
            }
        }

        return ans;
    }
};
