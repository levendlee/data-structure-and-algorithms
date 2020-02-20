#include "common.hpp"

struct Object {
    int color;
    int cata;
};

// Greedy
vector<vector<int>> PairObjects1(const vector<Object>& objects) {
    const int n = objects.size();

    vector<vector<int>> pairs;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int score = (objects[i].color != objects[j].color) + \
                        (objects[i].cata != objects[j].cata);
            pairs.push_back({-score, i, j});
        }
    }

    sort(pairs.begin(), pairs.end());

    vector<vector<int>> res;
    vector<bool> paired(n, false);
    for (auto& p : pairs) {
        if (paired[p[1]] || paired[p[2]]) continue;
        paired[p[1]] = true;
        paired[p[2]] = true;
        res.push_back({p[1], p[2]});
    }

    return res;
}

// Munkres
vector<vector<int>> PairObjects2(const vector<Object>& objects) {
    const int n = objects.size();

    vector<vector<int>> scores(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scores[i][j] = (objects[i].color != objects[j].color) + \
                           (objects[i].cata != objects[j].cata);
        }
    }

    vector<bool> used(n, false);
    vector<int> matched(n, -1);
    int total_scores = 0;
    auto find_match = [&](int i, int target_score) {
        for (int j = 0; j < n; ++j) {
            if (i == j || matched[j] != -1) continue;
            if (scores[i][j] == target_score) {
                total_scores += target_score;
                matched[i] = j;
                matched[j] = i;
                cout << i << "+" << j << "\n";
                return true;
            }
        }
        return false;
    };

    for (int target_score = 2; target_score >= 0; --target_score) {
        for (int i = 0; i < n; ++i) {
            if (matched[i] != -1) continue;
            if (find_match(i, target_score)) continue;
            for (int j = 0; j < n; ++j) {
                if (i == j || scores[i][j] != target_score) continue;
                auto replace = matched[j];
                if (find_match(replace, target_score)) {
                    matched[i] = j;
                    matched[j] = i;
                }
            }
        }
    }

    vector<vector<int>> res;
    for (int i = 0; i < n; ++i) {
        if (matched[i] > i) {
            res.push_back({i, matched[i]});
        }
    }
    return res;
}


int main() {
    vector<Object> objects = {{0, 1}, {1, 3}, {1, 3}, {1, 2}, {0, 2}, {1, 5}};
    auto res = PairObjects1(objects);
    for (auto& p : res) cout << p[0] << "," << p[1] << "; ";
    cout << "\n";
    return 0;
}