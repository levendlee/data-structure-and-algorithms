// https://leetcode.com/discuss/interview-question/476340/Google-or-Onsite-or-Min-Modifications
#include "common.hpp"

int findMinModifications(vector<vector<char>>& matrix) {
    const int m = matrix.size();
    if (m == 0) return 0;
    const int n = matrix[0].size();
    if (n == 0) return 0;

    if (m == 1 && n == 1) return 0;

    vector<vector<int>> visited(m, vector<int>(n, INT_MAX));
    priority_queue<vector<int>> pq;
    pq.push({0, 0, 0});
    visited[0][0] = true;

    auto push_pq = [&](int i, int j, bool match, int cost) {
        if (i < 0 || i >= m || j < 0 || j >= n) return;
        auto ncost = match ? cost : cost + 1;
        if (visited[i][j] <= ncost) return;
        visited[i][j] = ncost;
        //cout << "push " << i << "," << j << "->" << ncost << "\n";
        pq.push({-ncost, i, j});
    };

    while (!pq.empty()) {
        auto cost = -pq.top()[0];
        auto i = pq.top()[1];
        auto j = pq.top()[2];
        //cout << i << "," << j << "->" << cost << "\n";
        pq.pop();

        push_pq(i + 1, j, matrix[i][j] == 'D', cost);
        push_pq(i - 1, j, matrix[i][j] == 'U', cost);
        push_pq(i, j + 1, matrix[i][j] == 'R', cost);
        push_pq(i, j - 1, matrix[i][j] == 'L', cost);
    }

    return visited[m-1][n-1] == INT_MAX ? -1 : visited[m-1][n-1];
}

int main() {
    vector<vector<char>> matrix = {{'R', 'R', 'D'}, {'L', 'L', 'L'}, {'U', 'U', 'R'}};
    cout << findMinModifications(matrix) << "\n";
    return 0;
}